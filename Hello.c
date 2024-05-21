#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void neg(unsigned char in[], int n)
{
    int i, carry;                                           // ������ ��������
    unsigned w;                              // ������� ���������� ��� �������� ���� ������
    for (i = 0; i < n; i++) in[i] = ~in[i];      // �������������� ���� ��������
    for (i = 0, carry = 1; i < n; i++) {         // ���������� 1 (���������) � ��������������
        in[i] = w = in[i] + carry;          // ���������� �������� � 1
        carry = (w & 0x0100) >> 8;
    }
}

void add(unsigned char out[], unsigned char in1[], unsigned char in2[], int n)
{
    int i, carry;                                 // ������ ��������
    unsigned w;                              // ������� ���������� ��� �������� ���� ������
    for (i = 0, carry = 0; i < n; i++) {
        out[i] = w = in1[i] + in2[i] + carry;
        carry = (w & 0x0100) >> 8;    // ������ �������� �������� ������ �� 8
    }
}
//------����� ����� ������������ �����������
void lshift(unsigned char in[], int n)
{
    int carry;                                            // ������ ��������
    int i, z;
    for (carry = 0, i = 0; i < n; i++) {
        z = (in[i] & 0x80) >> 7;                         // �������� ������� ������ (�������)
        in[i] <<= 1;                                      // �������� ����� � ����������
        in[i] |= carry;                                     // ������ ������� � ������� ������
        carry = z;                                        // ��������� ����� �������
    }
}
void rshift(unsigned char in[], int n)                      // ����� ��������������
{
    int carry = ((in[n - 1] & 0x80) != 0);   // ������ �������� = ����� ���������
    int i, z;
    for (i = n - 1; i >= 0; i--) {
        z = in[i] & 1;                                    // �������� ������� ������ (�������)
        in[i] >>= 1;                                      // �������� ������ � ����������
        in[i] |= carry << 7;                             // ������ ������� � ������� ������
        carry = z;                                        // ��������� ����� �������
    }
}

void mul(unsigned char out[], unsigned char aa[], unsigned char bb[], int n)
{
    int i, s1 = 0, s2 = 0;                                               // ������������� ����� - ������ ���
    if (aa[n - 1] & 0x80) { neg(aa, n); s1 = 1; }
    if (bb[n - 1] & 0x80) { neg(bb, n); s2 = 1; }
    for (i = 0; i < n; i++) out[i] = 0;
    for (i = 0; i < n * 8; i++) {                                    // ���� �� ���������� ��������
        if (bb[0] & 1)                                               // ������ ��������� ����� 1
            add(out, out, aa, n);                                   // �������� �������� � ������������
        lshift(aa, n);                                                  // �������� - �����
        rshift(bb, n);                                                  // ��������� - ������
    }
    if (s1 != s2) neg(out, n);                                        // ����� �� ��������� - ���. ���
    printf("%s", out);
}

void main()
{
    long a = 1234, b = 4567, c;
    mul((unsigned char*)&c, (unsigned char*)&a, (unsigned char*)&b, sizeof(long));
    printf("%ld\n", c);
}