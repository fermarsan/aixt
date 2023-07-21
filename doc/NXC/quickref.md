# Quick reference for NXC (Mindstorms NXT)

This **Aixt** port works as a **NXC** language wrapper, keeping the same function names, but using _snake\_case_ instead of _CamelCase_. For instance this **Aixt** code:
```go
on_fwd(out_a, 75)   // alternatively: on_forward()  
on_fwd(out_c, 75)
wait(4000)          // alternatively: sleep()  
on_rev(out_ac, 75)  // alternatively: on_reverse()  
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
[task] fn move_square() {
    for {
        acquire(move_mutex)
        on_forward(out_ac, 75); sleep(1000)
        on_reverse(out_c, 75); sleep(500)
        release(move_mutex)
    }
}

[task] fn check_sensors() {
    for {
        if sensor_1 == 1 {
            acquire(move_mutex)
            on_reverse(out_ac, 75); sleep(500)
            on_forward(out_a, 75); sleep(500)
            release(move_mutex)
        }
    }
}

move_mutex := mutex('') //initialization value is necesary but will be ingnored

precedes(move_square, check_sensors)
set_sensor_touch(in_1)
```

will be transpiled to:
```c
mutex move_mutex;

task move_square()
{
    while (true)
    {
        Acquire(move_mutex);
        OnFwd(OUT_AC, 75); 
        Wait(1000);
        OnRev(OUT_C, 75); 
        Wait(500);
        Release(move_mutex);
    }
}

task check_sensors()
{
    while (true)
    {
        if (SENSOR_1 == 1)
        {
            Acquire(move_mutex);
            OnRev(OUT_AC, 75); 
            Wait(500);
            OnFwd(OUT_A, 75); 
            Wait(500);
            Release(move_mutex);
        }
    }
}

task main()
{
    Precedes(move_square, check_sensors);
    SetSensorTouch(IN_1);
}
```

The NXC port of **Aixt** can be used in _script_ mode (without main function). In that case the _mutex_ variables have to be "declared" after _task_ functions definition, as shown in the previous example.

# Installing
`Aixt` project includes the `nbc` compiler for both _Windows_ and _Linux_, but you have to install manually the USB drivers.

## for Windows
Download the _NXT_ software from (https://education.lego.com/en-us/downloads/retiredproducts/nxt/software)[https://education.lego.com/en-us/downloads/retiredproducts/nxt/software], and install only the drivers.


## for Linux
Install the last version of `libusb-dev` package acording to your distribution. For instance in _Ubuntu_ you can type in a terminal:
```
apt-get install libusb-dev
```