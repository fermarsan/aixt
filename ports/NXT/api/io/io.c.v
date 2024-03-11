module io

// cstdio.h
#define     io__fclose(...)         fclose(__VA_ARGS__)
#define     io__remove(...)         remove(__VA_ARGS__)
#define     io__rename(...)         rename(__VA_ARGS__)
#define     io__fgetc(...)          fgetc(__VA_ARGS__)
#define     io__fgets(...)          fgets(__VA_ARGS__)
#define     io__feof(...)           feof(__VA_ARGS__)
#define     io__set_fopen_size(...) set_fopen_size(__VA_ARGS__)
#define     io__fopen(...)          fopen(__VA_ARGS__)
#define     io__fflush(...)         fflush(__VA_ARGS__)
#define     io__ftell(...)          ftell(__VA_ARGS__)
#define     io__fputc(...)          fputc(__VA_ARGS__)
#define     io__fputs(...)          fputs(__VA_ARGS__)
#define     io__getchar(...)        getchar(__VA_ARGS__)
#define     io__printf(...)         printf(__VA_ARGS__)
#define     io__fprintf(...)        fprintf(__VA_ARGS__)
#define     io__sprintf(...)        sprintf(__VA_ARGS__)
#define     io__fseek(...)          fseek(__VA_ARGS__)
#define     io__rewind(...)         rewind(__VA_ARGS__)

#define 	io__getc(...)   		fgetc(__VA_ARGS__)
#define 	io__putc(...)   		fputc(__VA_ARGS__)

fn init() {

}