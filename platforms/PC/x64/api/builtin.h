#ifndef _BUILTIN_H_
#define _BUILTIN_H_

#include <stdio.h>
#include <string.h>

#define print(STR)      printf(STR)
#define println(STR)    printf(STR); printf("\n")

#define string__assign(DEST, SOURCE)    strcpy(DEST, SOURCE) 

#endif  // _BUILTIN_H_