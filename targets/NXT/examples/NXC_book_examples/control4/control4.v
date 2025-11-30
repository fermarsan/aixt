import sensor { Sensor }

mut my_sensor := Sensor.new(sensor.s3)
my_sensor.write_type(sensor.type_light_inactive)
my_sensor.write_mode(sensor.mode_pct_full_scale)
my_sensor.reset()
