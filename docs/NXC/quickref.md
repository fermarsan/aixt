# Quick reference for NXC (Mindstorms NXT)

This **Aixt** port works as a **NXC** language wrapper, keeping the same function names, but using _snake case_ instead of _Camel Case_. For instance this **Aixt** code:

```go
on_fwd(out_A, 75)
on_fwd(out_C, 75)
wait(4000)
on_rev(out_AC, 75)
wait(4000)
off(out_AC)
```
will be transpiled to:

```c
task main()
{
    OnFwd(OUT_A, 75);
    OnFwd(OUT_C, 75);
    Wait(4000);
    OnRev(OUT_AC, 75);
    Wait(4000);
    Off(OUT_AC);
}
```
