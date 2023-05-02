// This file is part of the Aixt project, https://gitlab.com/fermarsan/aixt-project.git
//
// The MIT License (MIT)
// 
// Copyright (c) 2022-2023 Fernando Martínez Santa

#include "os__input.h"

char *os__input(char *msg) {
    printf("%s", msg);
    scanf("%s", &in_str[0]);
    return in_str;
}