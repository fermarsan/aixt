# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\sources\\c90\\common\\doprnt.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:/Program Files/Microchip/MPLABX/v6.15/packs/Microchip/PIC16Fxxx_DFP/1.4.149/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\sources\\c90\\common\\doprnt.c" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\stdio.h" 1 3



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\__size_t.h" 1 3



typedef unsigned size_t;
# 5 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\stdio.h" 2 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\__null.h" 1 3
# 6 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\stdio.h" 2 3





# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\stdarg.h" 1 3






typedef void * va_list[1];

#pragma intrinsic(__va_start)
extern void * __va_start(void);

#pragma intrinsic(__va_arg)
extern void * __va_arg(void *, ...);
# 12 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\stdio.h" 2 3
# 43 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\stdio.h" 3
struct __prbuf
{
 char * ptr;
 void (* func)(char);
};
# 85 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\stdio.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\conio.h" 1 3







# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\errno.h" 1 3
# 29 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\errno.h" 3
extern int errno;
# 9 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\conio.h" 2 3



extern void init_uart(void);

extern char getch(void);
extern char getche(void);
extern void putch(char);
extern void ungetch(char);

extern __bit kbhit(void);



extern char * cgets(char *);
extern void cputs(const char *);
# 86 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\stdio.h" 2 3


extern int cprintf(char *, ...);
#pragma printf_check(cprintf)



extern int _doprnt(struct __prbuf *, const register char *, register va_list);
# 180 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\stdio.h" 3
#pragma printf_check(vprintf) const
#pragma printf_check(vsprintf) const

extern char * gets(char *);
extern int puts(const char *);
extern int scanf(const char *, ...) __attribute__((unsupported("scanf() is not supported by this compiler")));
extern int sscanf(const char *, const char *, ...) __attribute__((unsupported("sscanf() is not supported by this compiler")));
extern int vprintf(const char *, va_list) __attribute__((unsupported("vprintf() is not supported by this compiler")));
extern int vsprintf(char *, const char *, va_list) __attribute__((unsupported("vsprintf() is not supported by this compiler")));
extern int vscanf(const char *, va_list ap) __attribute__((unsupported("vscanf() is not supported by this compiler")));
extern int vsscanf(const char *, const char *, va_list) __attribute__((unsupported("vsscanf() is not supported by this compiler")));

#pragma printf_check(printf) const
#pragma printf_check(sprintf) const
extern int sprintf(char *, const char *, ...);
extern int printf(const char *, ...);
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\sources\\c90\\common\\doprnt.c" 2

# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\ctype.h" 1 3



extern __bit isalpha(char);
extern __bit isupper(char);
extern __bit islower(char);
extern __bit isdigit(char);
extern __bit isxdigit(char);
extern __bit isspace(char);
extern __bit ispunct(char);
extern __bit isalnum(char);
extern __bit isprint(char);
extern __bit isgraph(char);
extern __bit iscntrl(char);


extern char toupper(char);
extern char tolower(char);
# 2 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\sources\\c90\\common\\doprnt.c" 2

# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\stdlib.h" 1 3






typedef unsigned short wchar_t;







typedef struct {
 int rem;
 int quot;
} div_t;
typedef struct {
 unsigned rem;
 unsigned quot;
} udiv_t;
typedef struct {
 long quot;
 long rem;
} ldiv_t;
typedef struct {
 unsigned long quot;
 unsigned long rem;
} uldiv_t;
# 65 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\stdlib.h" 3
extern double atof(const char *);
extern double strtod(const char *, const char **);
extern int atoi(const char *);
extern unsigned xtoi(const char *);
extern long atol(const char *);



extern long strtol(const char *, char **, int);

extern int rand(void);
extern void srand(unsigned int);
extern void * calloc(size_t, size_t);
extern div_t div(int numer, int denom);
extern udiv_t udiv(unsigned numer, unsigned denom);
extern ldiv_t ldiv(long numer, long denom);
extern uldiv_t uldiv(unsigned long numer,unsigned long denom);



extern unsigned long _lrotl(unsigned long value, unsigned int shift);
extern unsigned long _lrotr(unsigned long value, unsigned int shift);
extern unsigned int _rotl(unsigned int value, unsigned int shift);
extern unsigned int _rotr(unsigned int value, unsigned int shift);




extern void * malloc(size_t);
extern void free(void *);
extern void * realloc(void *, size_t);




# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\xc8debug.h" 1 3
# 13 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\xc8debug.h" 3
#pragma intrinsic(__builtin_software_breakpoint)
extern void __builtin_software_breakpoint(void);
# 100 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\stdlib.h" 2 3




extern int atexit(void (*)(void));
extern char * getenv(const char *);
extern char ** environ;
extern int system(char *);
extern void qsort(void *, size_t, size_t, int (*)(const void *, const void *));
extern void * bsearch(const void *, void *, size_t, size_t, int(*)(const void *, const void *));
extern int abs(int);
extern long labs(long);

extern char * itoa(char * buf, int val, int base);
extern char * utoa(char * buf, unsigned val, int base);




extern char * ltoa(char * buf, long val, int base);
extern char * ultoa(char * buf, unsigned long val, int base);

extern char * ftoa(float f, int * status);
# 3 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\sources\\c90\\common\\doprnt.c" 2

# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\string.h" 1 3
# 14 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\string.h" 3
extern void * memcpy(void *, const void *, size_t);
extern void * memmove(void *, const void *, size_t);
extern void * memset(void *, int, size_t);
# 36 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\string.h" 3
extern char * strcat(char *, const char *);
extern char * strcpy(char *, const char *);
extern char * strncat(char *, const char *, size_t);
extern char * strncpy(char *, const char *, size_t);
extern char * strdup(const char *);
extern char * strtok(char *, const char *);


extern int memcmp(const void *, const void *, size_t);
extern int strcmp(const char *, const char *);
extern int stricmp(const char *, const char *);
extern int strncmp(const char *, const char *, size_t);
extern int strnicmp(const char *, const char *, size_t);
extern void * memchr(const void *, int, size_t);
extern size_t strcspn(const char *, const char *);
extern char * strpbrk(const char *, const char *);
extern size_t strspn(const char *, const char *);
extern char * strstr(const char *, const char *);
extern char * stristr(const char *, const char *);
extern char * strerror(int);
extern size_t strlen(const char *);
extern char * strchr(const char *, int);
extern char * strichr(const char *, int);
extern char * strrchr(const char *, int);
extern char * strrichr(const char *, int);
# 4 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\sources\\c90\\common\\doprnt.c" 2



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\math.h" 1 3



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\__unsupported.h" 1 3
# 5 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\math.h" 2 3
# 30 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\math.h" 3
extern double fabs(double);
extern double floor(double);
extern double ceil(double);
extern double modf(double, double *);
extern double sqrt(double);
extern double atof(const char *);
extern double sin(double) ;
extern double cos(double) ;
extern double tan(double) ;
extern double asin(double) ;
extern double acos(double) ;
extern double atan(double);
extern double atan2(double, double) ;
extern double log(double);
extern double log10(double);
extern double pow(double, double) ;
extern double exp(double) ;
extern double sinh(double) ;
extern double cosh(double) ;
extern double tanh(double);
extern double eval_poly(double, const double *, int);
extern double frexp(double, int *);
extern double ldexp(double, int);
extern double fmod(double, double);
extern double trunc(double);
extern double round(double);
# 7 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\sources\\c90\\common\\doprnt.c" 2

# 1 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\include\\c90\\float.h" 1 3
# 8 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\sources\\c90\\common\\doprnt.c" 2




#pragma warning disable 350
# 358 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\sources\\c90\\common\\doprnt.c"
const static unsigned int dpowers[] = {1, 10, 100, 1000, 10000,




        };
# 463 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\sources\\c90\\common\\doprnt.c"
int
# 505 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\sources\\c90\\common\\doprnt.c"
sprintf(char * sp, const char * f, ...)
{
 va_list ap;




 char c;
# 521 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\sources\\c90\\common\\doprnt.c"
 signed char prec;



 unsigned char flag;
# 540 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\sources\\c90\\common\\doprnt.c"
 union {
  unsigned long vd;
  double integ;
 } tmpval;

 unsigned int val;
 unsigned len;
 const char * cp;


 *ap = __va_start();


 while((c = *f++)) {

  if(c != '%')

  {
   ((*sp++ = (c)));
   continue;
  }




  flag = 0;
# 661 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\sources\\c90\\common\\doprnt.c"
  switch(c = *f++) {

  case 0:
   goto alldone;
# 828 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\sources\\c90\\common\\doprnt.c"
  default:
# 839 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\sources\\c90\\common\\doprnt.c"
   continue;



  case 'u':
   flag |= 0xC0;
   break;


  }
# 1299 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\sources\\c90\\common\\doprnt.c"
  {
# 1312 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\sources\\c90\\common\\doprnt.c"
    val = (*(unsigned *)__va_arg((*(unsigned **)ap), (unsigned)0));
  }
# 1331 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\sources\\c90\\common\\doprnt.c"
   for(c = 1 ; c != sizeof dpowers/sizeof dpowers[0] ; c++)
    if(val < dpowers[c])
     break;
# 1448 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\sources\\c90\\common\\doprnt.c"
  {
# 1495 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\sources\\c90\\common\\doprnt.c"
  }


  prec = c;

  while(prec--) {



   {
# 1515 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\sources\\c90\\common\\doprnt.c"
    c = (val / dpowers[(unsigned char)prec]) % 10 + '0';
# 1549 "C:\\Program Files\\Microchip\\xc8\\v2.41\\pic\\sources\\c90\\common\\doprnt.c"
   }
   ((*sp++ = (c)));
  }







 }

alldone:


 *sp = 0;

 return 0;
}
