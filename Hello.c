#include <stdio.h>
#include <locale.h>
#include <string.h>

struct man2 {

	char name[20];

	char* zodiak;

	struct man2* next;

} 
C2[3] = {

{"Петров","Весы",NULL },

{"Сидоров","Дева",&C2[0] },

{"Иванов","Козерог",&C2[1] } };

void F2() {
	setlocale(LC_ALL, "Rus");
	char c1, c2, c3, c4;

	c1 = C2[0].name[2]; //т из Иванов
	c2 = C2[1].zodiak[3]; //а из Дева
	c3 = C2[2].next->name[3]; //о Из Сидоров
	c4 = C2[2].next->next->zodiak[1]; //е из Весы

	printf("%c \n", c1);
	printf("%c \n", c2);
	printf("%c \n", c3);
	printf("%c \n", c4);
}

struct tree3 {

	int vv;

	struct tree3* l, * r;
}

A3 = { 1,NULL,NULL }, 
B3 = { 2,NULL,NULL },
C3 = { 3, &A3, &B3 }, 
D3 = { 4, &C3, NULL },

* p3 = &D3;

void F3() 
{ 
	int i1, i2, i3, i4;  
	i1 = A3.vv; //1
	i2 = D3.l->vv; //3
	i3 = p3->l->r->vv; //2
	i4 = p3->vv; //4

	printf("%d \n", i1);
	printf("%d \n", i2);
	printf("%d \n", i3);
	printf("%d \n", i4);
}
void main()
{
	F2();
	printf("\n");
	F3();
}