#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <limits.h>

#define _CRT_SECURE_NO_WARNINGS

void findAndRemoveBrackets(char** strings) 
{
    char szString[] = "KKK";
    strcpy_s(strings[1], 80, szString);
}

int main() {
    char strings[100][80];
    char** pc;

    pc = (char**)malloc(100 * sizeof(char*));
    scanf_s("%s", strings[0]);

    for (int i = 0; i < 100; i++)
    {
        pc[i] = (char*)malloc(80 * sizeof(char));
        pc[i] = strings[i];
    }
    findAndRemoveBrackets(pc);

    printf("%s\n", strings[1]);

    return 0;
}