import time {sleep_ms}
import pin

b0n := false

pin.setup(led, pin.output)
pin.setup(gp11, pin.input)

for {
if (pin.read(gp11))
{
sleep_ms(50)
while(pin.read(gp11))
sleep_ms(50)
b0n = ! b0n

if(b0n) 
pin.high(led)

else 
pin.low(led)
}
}