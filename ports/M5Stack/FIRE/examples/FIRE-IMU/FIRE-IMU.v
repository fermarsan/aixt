// Project name: IMU test
// Author: Fernando M
// Date: 22/01/2025
// M5Stack FIRE IoT development kit

import lcd 
import imu
import power
import time

// Define variables for storing inertial sensor data
acc_x, acc_y, acc_z := f32(0.0), f32(0.0), f32(0.0)
gyro_x,gyro_y,gyro_z := f32(0.0), f32(0.0), f32(0.0)
pitch,roll,yaw := f32(0.0), f32(0.0), f32(0.0)
temp  := f32(0.0)

power.setup()  // Init Power module
imu.setup()  // Init IMU sensor
lcd.fill_screen(lcd.black)  // Set the screen background color to black
lcd.text_color_bg(lcd.green, lcd.black)  // foreground color and background color of the text
// lcd.text_size(2)  // Set the font size

for {
    // Stores the triaxial gyroscope data of the inertial sensor to the relevant
    // variable
    imu.get_gyro_data(&gyro_x, &gyro_y, &gyro_z)
    imu.get_accel_data(&acc_x, &acc_y, &acc_z)  // stores the triaxial accelerometer
    imu.get_ahrs_data(&pitch, &roll, &yaw)  // Stores the inertial sensor attitude
    imu.get_temp_data(&temp)  // Stores the inertial sensor temperature to temp

    /* The M5Core screen is 320x240 pixels, starting at the top left corner of
    the screen (0,0).*/
    // gyroscope output related
    lcd.cursor(0, 20)  // Move the cursor position to (x,y)
    lcd.print('gyroX,  gyroY, gyroZ')  // Screen printing formatted string
    lcd.cursor(0, 42)
    lcd.print('${gyro_x} ${gyro_y} ${gyro_z} o/s')

    // Accelerometer output is related
    lcd.cursor(0, 70)
    lcd.print('accX,   accY,  accZ')
    lcd.cursor(0, 92)
    lcd.print('${acc_x} ${acc_y} ${acc_z} G')

    // Pose output is related
    lcd.cursor(0, 120)
    lcd.print('pitch,  roll,  yaw')
    lcd.cursor(0, 142)
    lcd.print('${pitch}, ${roll}, ${yaw} deg')

    // Inertial sensor temperature output related
    lcd.cursor(0, 175)
    lcd.print('Temperature : ${temp} C')

    time.sleep_ms(10)  // Delay 10ms  
}