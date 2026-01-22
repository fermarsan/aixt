module io

// cstdio.h
@[inline] fclose() { return C.fclose() }
@[inline] remove() { return C.remove() }
@[inline] rename() { return C.rename() }
@[inline] fgetc() { return C.fgetc() }
@[inline] fgets() { return C.fgets() }
@[inline] feof() { return C.feof() }
@[inline] set_fopen_size() { return C.set_fopen_size() }
@[inline] fopen() { return C.fopen() }
@[inline] fflush() { return C.fflush() }
@[inline] ftell() { return C.ftell() }
@[inline] fputc() { return C.fputc() }
@[inline] fputs() { return C.fputs() }
@[inline] getchar() { return C.getchar() }
@[inline] printf() { return C.printf() }
@[inline] fprintf() { return C.fprintf() }
@[inline] sprintf() { return C.sprintf() }
@[inline] fseek() { return C.fseek() }
@[inline] rewind() { return C.rewind() }

@[inline] getc() { return C.fgetc() }
@[inline] putc() { return C.fputc() }
