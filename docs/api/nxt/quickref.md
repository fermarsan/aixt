# Quick reference for Mindstorms NXT brick

## Transpiled to NXC language

The _NXT_ **Aixt** target transpiles the source _V_ code to the **NXC** language. From the API version 0.2.0, the main modules (`motor`, `sensor` and `button`) have two versions: one that uses functional programming and another one that uses `struct`s and methods (object oriented approach). The following examples show the different ways to write a program for _NXT_.

- Using functional programming:

```v
import motor
import time

motor.write(motor.a, 75)    
motor.write(motor.c, 75)
time.sleep_ms(4000)          
motor.write(motors.ac, -75)  
time.sleep_ms(4000)
motor.off(motors.ac)
```

- using struct-based programming and module's global variables

```v
import motor
import time

motor_a.write(75)    
motor_c.write(75)
time.sleep_ms(4000)          
motors_ac.write(-75)  
time.sleep_ms(4000)
motors_ac.off()
```
```

- using struct-based programming and custom instances 

```v
import motor { Motor }
import time

mut left := Motor.new(motor.a)
mut right := Motor.new(motor.c)
mut left_right := Motor.new(motor.ac)

left.write(75)    
right.write(75)
time.sleep_ms(4000)          
leff_right.write(-75)  
time.sleep_ms(4000)
leff_right.off()
```


All of those codes is be equivalent to:
```c
task main()
{
    OnFwd(OUT_A, 75);
    OnFwd(OUT_C, 75);
    Wait(4000);
    OnFwd(OUT_AC, -75);
    Wait(4000);
    Off(OUT_AC);
}
```

## Multitasking
The **Aixt** port for **NXC** language supports _tasks_ by using attributes and special variable types. In this case the special alias type `Mutex` is used for implementing mutex variables, and the attribute `[@task]` for implementing task functions. For instance, the follow code: 

```v
import motor
import sensor { Sensor }
import time
import task


__global (
	move_mutex = Mutex(0)			// mutex variable
	touch = Sensor.new(sensor.s1)	// sensor variable
)

@[task]
fn move_square() {
	for {
		task.mutex_lock(move_mutex)
		motor_ac.write(75)
		time.sleep_ms(1000)
		motor_c.write(-75)	// reverse
		time.sleep_ms(500)
		task.mutex_unlock(move_mutex)
	}
}

@[task]
fn check_sensors() {
	for {
		if touch.read() == 1 {
			task.mutex_lock(move_mutex)
			motor_ac.write(-75)	// reverse
			time.sleep_ms(500)
			motor_a.write(75)
			time.sleep_ms(500)
			task.mutex_unlock(move_mutex)
		}
	}
}

touch.setup(sensor.touch)	// configure the sensor as touch
task.priority(move_square, check_sensors)
```

will be equivalent to:
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

The NXC port of **Aixt** can be used in _script_ mode (without main function). In that case the _Mutex_ variables have to be "declared" after _task_ functions definition, as shown in the previous example.

# Installing
`Aixt` project includes the `nbc` compiler for both _Windows_ and _Linux_, but you have to install manually the USB drivers.

## for Windows
Download the _NXT_ software from (https://education.lego.com/en-us/downloads/retiredproducts/nxt/software)[https://education.lego.com/en-us/downloads/retiredproducts/nxt/software], and install only the drivers.


## for Linux
Install the last version of `libusb-dev` package according to your distribution. For instance in a _Debian-based_ distribution you can type in a terminal:
```
apt-get install libusb-1.0-0-dev
```
or
```
apt-get install libusb-dev
```