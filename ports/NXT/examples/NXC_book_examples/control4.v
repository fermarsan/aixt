import sensor

sensor.setup_type(sensor.s3, sensor.type_light_inactive)
sensor.setup_mode(sensor.s3, sensor.mode_pctfullscale)
sensor.reset(sensor.s3)