moveMutex := mutex()

task move_square()
{
    while (true)
    {
        acquire(moveMutex)
        forward(motors_ac, 75)
        sleep(1000)
        OnRev(motor_c, 75)
        sleep(500)
        release(moveMutex)
    }
}

task check_sensors()
{
    while (true)
        {
        if (sensor_1 == 1)
        {
            acquire(moveMutex)
            on_rev(motors_ac, 75)
            sleep(500)
            forward(motor_a, 75)
            sleep(500)
            release(moveMutex)
        }
    }
}

task main()
{
    precedes(move_square, check_sensors);
    set_sensor_touch(in_1)
}