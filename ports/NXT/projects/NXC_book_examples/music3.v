@[task] fnmusic() {
    for {
        play_tone(262,400)
        sleep(500)
        play_tone(294,400)
        sleep(500)
        play_tone(330,400)
        sleep(500)
        play_tone(294,400)
        sleep(500)
    }
}

@[task] fnmovement() {
    for {
        forward(motors_ac, 75)
        sleep(3000)
        reverse(motors_ac, 75)
        sleep(3000)
    }
}

@[task] fnmain() {
    precedes(music, movement)
}
