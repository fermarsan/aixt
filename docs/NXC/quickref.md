# Quick reference for NXC (Mindstorms NXT)

This **Aixt** port works as a **NXC** language wrapper, keeping the same function names, but using _snake\_case_ instead of _CamelCase_. For instance this **Aixt** code:

```go
on_fwd(out_a, 75)
on_fwd(out_c, 75)
wait(4000)
on_rev(out_ac, 75)
wait(4000)
off(out_ac)
```
will be transpiled to:

```c
task main()
{
    OnFwd(OUT_A, 75);
    OnFwd(OUT_C, 75);
    Wait(4000);
    OnRev(OUT_AC, 75);
    Wait(4000);
    Off(OUT_AC);
}
```

## Multitasking
The **Aixt** port for **NXC** language suports _tasks_ by using attributes and special variable types. In this case the special type `mutex` is used for implementing mutex variables, and the attribute `[task]` for implementing task functions. For instance, the follow code: 

```go
[mutex] move_mutex := true //initialization value is necesary but will be ingnored 

[task] fn move_square() {
    for {
        acquire(move_mutex)
        on_fwd(out_ac, 75); wait(1000)
        on_rev(out_c, 75); wait(500)
        release(move_mutex)
    }
}

[task] fn check_sensors() {
    for {
        if sensor_1 == 1 {
            acquire(move_mutex)
            on_rev(out_ac, 75); wait(500)
            on_fwd(out_a, 75); wait(500)
            release(move_mutex)
        }
    }
}

precedes(move_square, check_sensors)
set_sensor_touch(in_1)
```

will be transpiled to:

```c
mutex moveMutex;

task move_square()
{
    while (true)
    {
        Acquire(moveMutex);
        OnFwd(OUT_AC, 75); 
        Wait(1000);
        OnRev(OUT_C, 75); 
        Wait(500);
        Release(moveMutex);
    }
}

task check_sensors()
{
    while (true)
    {
        if (SENSOR_1 == 1)
        {
            Acquire(moveMutex);
            OnRev(OUT_AC, 75); 
            Wait(500);
            OnFwd(OUT_A, 75); 
            Wait(500);
            Release(moveMutex);
        }
    }
}

task main()
{
    Precedes(move_square, check_sensors);
    SetSensorTouch(IN_1);
}
```
