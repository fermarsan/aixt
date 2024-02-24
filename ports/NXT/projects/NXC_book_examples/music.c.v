#define TIME 200
#define MAXVOL 7
#define MINVOL 1
#define MIDVOL 3
#define pause_4th sleep(TIME)
#define pause_8th sleep(TIME/2)
#define note_4th play_file_ex("! Click.rso",MIDVOL,FALSE); pause_4th
#define note_8th play_file_ex("! Click.rso",MAXVOL,FALSE); pause_8th

play_file_ex("! Startup.rso",MINVOL,FALSE)
sleep(2000)
note_4th
note_8th
note_8th
note_4th
note_4th
pause_4th
note_4th
note_4th
sleep(100)
