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
	struct Student first = { "Рехтин", 123456, "АВТФ", "АВТ-341" };
	printf("Фамилия: %s \t Номер билета: %d \t Факультет: %s \t Группа: %s \n", first.surname, first.bookNumber, first.faculti, first.group);
}