# module m5stack.core.imu


## Contents
- [fifo_enable](#fifo_enable)
- [get_accel_adc](#get_accel_adc)
- [get_accel_data](#get_accel_data)
- [get_ahrs_data](#get_ahrs_data)
- [get_ares](#get_ares)
- [get_gres](#get_gres)
- [get_gyro_adc](#get_gyro_adc)
- [get_gyro_data](#get_gyro_data)
- [get_temp_adc](#get_temp_adc)
- [get_temp_data](#get_temp_data)
- [read_fifo](#read_fifo)
- [read_fifo_buff](#read_fifo_buff)
- [read_fifo_count](#read_fifo_count)
- [rest_fifo](#rest_fifo)
- [setup](#setup)

## fifo_enable
```v
fn fifo_enable(enable_flag bool)
```

[[Return to contents]](#Contents)

## get_accel_adc
```v
fn get_accel_adc(ax &i16, ay &i16, az &i16)
```

[[Return to contents]](#Contents)

## get_accel_data
```v
fn get_accel_data(ax &f32, ay &f32, az &f32)
```

[[Return to contents]](#Contents)

## get_ahrs_data
```v
fn get_ahrs_data(pitch &f32, roll &f32, yaw &f32)
```

[[Return to contents]](#Contents)

## get_ares
```v
fn get_ares()
```

[[Return to contents]](#Contents)

## get_gres
```v
fn get_gres()
```

[[Return to contents]](#Contents)

## get_gyro_adc
```v
fn get_gyro_adc(gx &i16, gy &i16, gz &i16)
```

[[Return to contents]](#Contents)

## get_gyro_data
```v
fn get_gyro_data(gx &f32, gy &f32, gz &f32)
```

[[Return to contents]](#Contents)

## get_temp_adc
```v
fn get_temp_adc(t &i16)
```

[[Return to contents]](#Contents)

## get_temp_data
```v
fn get_temp_data(t &f32)
```

[[Return to contents]](#Contents)

## read_fifo
```v
fn read_fifo()
```

[[Return to contents]](#Contents)

## read_fifo_buff
```v
fn read_fifo_buff(data_buf &u8, length u16)
```

[[Return to contents]](#Contents)

## read_fifo_count
```v
fn read_fifo_count()
```

[[Return to contents]](#Contents)

## rest_fifo
```v
fn rest_fifo()
```

[[Return to contents]](#Contents)

## setup
```v
fn setup() int
```

[[Return to contents]](#Contents)

#### Powered by vdoc. Generated on: 9 Feb 2026 16:33:30
