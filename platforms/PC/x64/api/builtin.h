// This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
//
// The MIT License (MIT)
// 
// Copyright (c) 2022-2023 Fernando Martínez Santa

#ifndef _BUILTIN_H_
#define _BUILTIN_H_

#include <stdio.h>
#include <string.h>

#define print(STR)      printf(STR)
#define println(STR)    printf(STR); printf("\n")

#define string__assign(DEST, SOURCE)    strcpy(DEST, SOURCE) 

#endif  // _BUILTIN_H_