moveMutex := mutex()

@[task] fn move_square() {
    for {
        acquire(moveMutex)
        forward(motors_ac, 75)
        sleep(1000)
        OnRev(motor_c, 75)
        sleep(500)
        release(moveMutex)
    }
}

@[task] fn check_sensors() {
    for {
        if (sensor_1 == 1)
        {
            acquire(moveMutex)
            reverse(motors_ac, 75)
            sleep(500)
            forward(motor_a, 75)
            sleep(500)
            release(moveMutex)
        }
    }
}

@[task] fn main() {
    precedes(move_square, check_sensors);
    set_sensor_touch(in_1)
}