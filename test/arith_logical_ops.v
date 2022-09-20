//arithmetic and logical operation test
fn main() {
    contador := i16(0)
    delta:= i16(1) 
    
    contador = 10
    contador = contador + delta / 2
    contador = delta*4 - 35.6
    delta = contador % 3
    delta = contador * (delta +2)

    estado := i8(0)
    condicion:=i8(0xAA)

    estado = estado & condicion
    estado = !estado | condicion
    estado = estado ^ !condicion
    estado = estado << 6
    estado = (condicion & estado) >> 2

    logic1 := true
    logic2 := false

    logic1 = (logic1 && logic2)
    logic2 = (logic1 || logic2)
}