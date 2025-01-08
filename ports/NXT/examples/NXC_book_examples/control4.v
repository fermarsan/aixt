import sensor

sensor.write_type(sensor.s3, sensor.type_light_inactive)
sensor.write_mode(sensor.s3, sensor.mode_pctfullscale)
sensor.reset(sensor.s3)