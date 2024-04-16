#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <limits.h>

#define _CRT_SECURE_NO_WARNINGS
int find(char c[]) {

    int i = 0; // Индекс в строке
    int k = 0; // Счетчик вложенности
    int max = -1; // Максимум вложенности
    int b = -1; // Индекс максимальной " ("

    for (i = 0, max = 0, b = -1; c[i] != 0; i++) {
        if (c[i] == ')') k--;
        if (c[i] == '(')
        {
            k++;
            if (k > max)
            {
                max = k;
                b = i;
            }
        }
    }
    if (b == -1) return 0; // Защита " от дурака" , нет парных скобок
    return max;
}

//Почини код на Си :
void findAndRemoveBrackets(char** strings)
{
    int j,i;
    int index = 0;
    int p = 1;
    while (find(strings[0]) && p < strlen(strings[0]))
    {
        for (i = 0; i < strlen(strings[0]); i++)
        {
            if (strings[0][i] == '(')
            {
                while (strings[0][i] == '(')
                {
                    i++;
                }
                j = i;
                while (strings[0][j] != ')')
                {

                    j++;
                    if (strings[0][j] == '(')
                    {
                        i = j;
                    }
                }
                /*for (int i = 0; i < strlen(strings[0]); i++)
                {
                    if (strings[0][i] == ')')
                    {
                        break;
                    }
                    if (strings[0][i] == '(')
                    {
                        index = i;
                    }
                    if (i == strlen(strings[0]) - 2 && strings[0][i + 1] != '(')
                    {
                        memmove(&strings[0][index], &strings[0][index + 1], strlen(strings[0]) - 1);

                    }
                }*/
                strncpy_s(strings[p], j - i, &strings[0][i + 1], j - i - 1);
                p++;
                //printf("%d %d %d\n", i, j, strlen(strings[0]));
                
                if (j == strlen(strings[0]) - 3)
                {
                    memmove(&strings[0][i-1], &strings[0][i] + (j-i+1), strlen(strings[0]) - (j-i+2));

                    return;
                }
                memmove(&strings[0][i], &strings[0][j + 1], strlen(strings[0]) - (j - i + 1));
            }
        }
    }
    p--;
    strncpy_s(strings[p], 2, &strings[p][0], 1);
}


int main()
{
    char strings[100][80];
    char** pc;
    char empty[] = "             ";

    pc = (char**)malloc(100 * sizeof(char*));
    scanf_s("%s", strings[0]);//qqq(ww(ee(r)))yy

    for (int i = 0; i < 100; i++)
    {
        pc[i] = (char*)malloc(80 * sizeof(char));
        pc[i] = strings[i];
    }
    findAndRemoveBrackets(pc);

    printf("%s\n", strings[0]);
    printf("%s\n", strings[1]);
    printf("%s\n", strings[2]);
    printf("%s\n", strings[3]);

    return 0;
}