move_mutex := mutex('') //initialization value is necesary but will be ingnored 

// [task] fn move_square() {
//     for {
//         acquire(move_mutex)
//         on_fwd(out_ac, 75); wait(1000)
//         on_rev(out_c, 75); wait(500)
//         release(move_mutex)
//     }
// }

// [task] fn check_sensors() {
//     for {
//         if sensor_1 == 1 {
//             acquire(move_mutex)
//             on_rev(out_ac, 75); wait(500)
//             on_fwd(out_a, 75); wait(500)
//             release(move_mutex)
//         }
//     }
// }

// precedes(move_square, check_sensors)
// set_sensor_touch(in_1)