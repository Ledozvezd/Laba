#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void neg(unsigned char in[], int n)
{
    int i, carry;                                           // Разряд переноса
    unsigned w;                              // Рабочая переменная для сложения двух байтов
    for (i = 0; i < n; i++) in[i] = ~in[i];      // Инвертированин всех разрядов
    for (i = 0, carry = 1; i < n; i++) {         // Добавление 1 (инкремент) с первоначальной
        in[i] = w = in[i] + carry;          // установкой переноса в 1
        carry = (w & 0x0100) >> 8;
    }
}

void add(unsigned char out[], unsigned char in1[], unsigned char in2[], int n)
{
    int i, carry;                                 // Разряд переноса
    unsigned w;                              // Рабочая переменная для сложения двух байтов
    for (i = 0, carry = 0; i < n; i++) {
        out[i] = w = in1[i] + in2[i] + carry;
        carry = (w & 0x0100) >> 8;    // Разряд переноса сдвинуть вправо на 8
    }
}
//------Сдвиг целых произвольной разрядности
void lshift(unsigned char in[], int n)
{
    int carry;                                            // Разряд переноса
    int i, z;
    for (carry = 0, i = 0; i < n; i++) {
        z = (in[i] & 0x80) >> 7;                         // Выделить старший разряд (перенос)
        in[i] <<= 1;                                      // Сдвинуть влево и установить
        in[i] |= carry;                                     // старый перенос в младший разряд
        carry = z;                                        // Запомнить новый перенос
    }
}
void rshift(unsigned char in[], int n)                      // Сдвиг арифметический
{
    int carry = ((in[n - 1] & 0x80) != 0);   // Разряд переноса = копия знакового
    int i, z;
    for (i = n - 1; i >= 0; i--) {
        z = in[i] & 1;                                    // Выделить младший разряд (перенос)
        in[i] >>= 1;                                      // Сдвинуть вправо и установить
        in[i] |= carry << 7;                             // старый перенос в старший разряд
        carry = z;                                        // Запомнить новый перенос
    }
}

void mul(unsigned char out[], unsigned char aa[], unsigned char bb[], int n)
{
    int i, s1 = 0, s2 = 0;                                               // Отрицательные числа - прямой код
    if (aa[n - 1] & 0x80) { neg(aa, n); s1 = 1; }
    if (bb[n - 1] & 0x80) { neg(bb, n); s2 = 1; }
    for (i = 0; i < n; i++) out[i] = 0;
    for (i = 0; i < n * 8; i++) {                                    // Цикл по количеству разрядов
        if (bb[0] & 1)                                               // Разряд множителя равен 1
            add(out, out, aa, n);                                   // Добавить множимое к произведению
        lshift(aa, n);                                                  // Множимое - влево
        rshift(bb, n);                                                  // Множитель - вправо
    }
    if (s1 != s2) neg(out, n);                                        // Знаки не совпадают - доп. код
    printf("%s", out);
}

void main()
{
    long a = 1234, b = 4567, c;
    mul((unsigned char*)&c, (unsigned char*)&a, (unsigned char*)&b, sizeof(long));
    printf("%ld\n", c);
}