#include <stdio.h>
#include <locale.h>

struct Student
{
	char surname[20];
	int bookNumber;
	char faculti[10];
	char group[10];
};

void main(void)
{
	setlocale(LC_ALL, "Rus");
	struct Student first = { "������", 123456, "����", "���-341" };
	printf("�������: %s \t ����� ������: %d \t ���������: %s \t ������: %s \n", first.surname, first.bookNumber, first.faculti, first.group);
}