# Quick reference for Mindstorms NXT brick
## (transpiled to NXC language)

This **Aixt** port works as an **NXC** language wrapper. Most of the name functions keep the same function names, but using _snake\_case_ instead of _CamelCase_, but some of them are totally change. For instance this **Aixt** code:
```v
forward(motor_a, 75)    
forward(motor_c, 75)
sleep(4000)          
reverse(motors_ac, 75)  
sleep(4000)
off(motors_ac)
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
```v
@[task] fn move_square() {
    for {
        acquire(move_mutex)
        forward(motors_ac, 75)
        sleep(1000)
        reverse(motor_c, 75)
        sleep(500)
        release(move_mutex)
    }
}

@[task] fn check_sensors() {
    for {
        if sensor_1 == 1 {
            acquire(move_mutex)
            reverse(motors_ac, 75)
            sleep(500)
            forward(motor_a, 75)
            sleep(500)
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

The complete list of the equivalences is in [NXT.toml](ports/setup/NXT.toml) file in the dictionary named `aliases`.

The NXC port of **Aixt** can be used in _script_ mode (without main function). In that case the _mutex_ variables have to be "declared" after _task_ functions definition, as shown in the previous example.

# Installing
`Aixt` project includes the `nbc` compiler for both _Windows_ and _Linux_, but you have to install manually the USB drivers.

## for Windows
Download the _NXT_ software from (https://education.lego.com/en-us/downloads/retiredproducts/nxt/software)[https://education.lego.com/en-us/downloads/retiredproducts/nxt/software], and install only the drivers.


## for Linux
Install the last version of `libusb-dev` package acording to your distribution. For instance in a _Debian-based_ distribution you can type in a terminal:
```
apt-get install libusb-1.0-0-dev
```
or
```
apt-get install libusb-dev
```