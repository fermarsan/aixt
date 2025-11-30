global_1 := i16(34)
global_2 := i16(125)

fn main() {
    local = 45
    local_2 = i32(0)
}

//borra la variable global 1
fn borra_global_1() {
    global_1 = 0
}

//borra la variable global pasada como argumento
fn borra(g i16) {
    g = 0
}

//retorna cero
fn cero() i16 {
    // return 0
}

//suma y carga el resultado a una variable local
fn suma_1(v1 i16, v2 i16) {
    global_1 = v1 + v2
}

//suma y retorno del resultado
fn suma_2(v1 i16, v2 i16) i16{
    // return v1 + v2
}