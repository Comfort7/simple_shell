#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* str_concat(const char* str1, const char* str2) {
    char* result = (char*)malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

