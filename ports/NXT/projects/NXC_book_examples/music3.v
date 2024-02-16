task music()
{
 while (true)
 {
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
task movement()
{
 while(true)
 {
 forward(motor_ac, 75)
  sleep(3000)
 on_rev(motor_ac, 75)
  sleep(3000);
 }
}
task main()
{
 precedes(music, movement);
}
