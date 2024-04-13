#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <limits.h>

#define _CRT_SECURE_NO_WARNINGS

int amount = 0;

struct Student
{
	char surname[50];
	int bookNumber[50];
	char faculti[50];
	char group[50];
};

void Add(struct Student* student)
{
	setlocale(LC_ALL, "Rus");
	if (amount < 35)
	{
		printf("\nEnter Surname:");
		scanf_s("%s", &student[amount].surname);
		printf("\nEnter Book Name:");
		scanf_s("%d", &student[amount].bookNumber);
		printf("\nEnter Faculti:");
		scanf_s("%s", &student[amount].faculti);
		printf("\nEnter Group:");
		scanf_s("%s", &student[amount].group); 
		amount++;
	}
	else
	{
		printf("Воу, воу, попридержи коней");
	}

}

void SaveTable(struct Student* student)
{
	FILE* file = fopen(file, "output.txt", "w");;
	for (int i = 0; i < amount; i++)
	{
		fprint(file, "%s %d %s %s", student[i].surname, student[i].bookNumber, student[i].faculti, student[i].group);
	}
	fclose(file);
	printf("Table was saved succesful");
}

void LoadTable(struct Student* student)
{
	FILE* file = fopen("output.txt", "r");

	while (fscanf(file, "%s %s %s %d\n", student[amount].surname, &student[amount].bookNumber, student[amount].faculti, student[amount].group) != EOF)
	{
		amount++;
	}

	fclose(file);
	printf("Table load from file.\n");
}


void ShowTable(struct Student * student)
{
	printf("Surname \t Book Number \t Faculti \t Group \n");
	for (int i = 0; i < amount; i++)
	{
		printf("%s \t %d \t %s \t %s \n", student[i].surname, student[i].bookNumber, student[i].faculti, student[i].group);
	}
}

void SortTable(struct Student * student)
{
	struct Student temp = {" ",INT_MAX," ", " "};
	int index = 0;
	for (int i = 0; i < amount; i++)
	{
		for (int j = i; j < amount; j++)
		{
			if (temp.bookNumber > student[j].bookNumber)
			{
				temp = student[j];
				index = j;
			}
		}
		student[index] = student[i];
		student[i] = temp;

	}
	printf("Sorted!");
}

void FindParam_char(struct Student * student, char* surname)
{
	for (int i = 0; i < amount; i++)
	{
		if (student[i].surname == surname)
		{
			printf("%s \t %d \t %s \t %s \n", student[i].surname, student[i].bookNumber, student[i].faculti, student[i].group);
		}
		else
		{
			printf("Normal'no pishi");
		}
	}
}

void FindParam_int(struct Student* student, int bookNumber)
{
	for (int i = 0; i < amount; i++)
	{
		if (student[i].bookNumber == bookNumber)
		{
			printf("%s \t %d \t %s \t %s \n", student[i].surname, student[i].bookNumber, student[i].faculti, student[i].group);
		}
		else
		{
			printf("Normal'no pishi");
		}
	}
}

void Delete(struct Student * student, int index)
{
	if (index < amount)
	{
		for (int i = index; i < amount - 1; i++)
		{
			student[i] = student[i + 1];
		}
		printf("Deleted");
		amount--;
	}
	else
	{
		printf("Normal'no pishi");
	}
}

void ChangeParam(struct Student * student, int index)
{
	if (index < amount)
	{
		printf("\nEnter Surname:");
		scanf_s("%s", &student[index].surname);
		printf("\nEnter Book Name:");
		scanf_s("%d", &student[index].bookNumber);
		printf("\nEnter Faculti:");
		scanf_s("%s", &student[index].faculti);
		printf("\nEnter Group:");
		scanf_s("%s", &student[index].group);
	}
	else
	{
		printf("Normal'no pishi");
	}
}

void main(void)
{
	struct Student students[100];

}
