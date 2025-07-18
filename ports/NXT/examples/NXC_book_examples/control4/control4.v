import sensor

sensor.write_type(sensor.s3, sensor.type_light_inactive)
sensor.write_mode(sensor.s3, sensor.mode_pct_full_scale)
sensor.reset(sensor.s3)