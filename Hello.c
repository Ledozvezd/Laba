#include <stdio.h>
#include <locale.h>
#include <string.h>

struct list 
{
    struct list* next;   
    void* pdata;
};                                      

struct list a1 = { NULL,"aaaa" }, a2 = { &a1,"bbbbbb" }, a3 = { &a2,"ccccc" }, * PH = &a3;
struct list int1 = { NULL, 54 }, int2 = { &int1, 521 }, int3 = { &int2, 1 }, * PHint = &int3;

void insertionSort(struct list* head) //list int
{
    struct list* sorted = NULL;
    struct list* current = head;

    while (current != NULL) {
        struct list* next = current->next;
        struct list* prev = NULL;
        struct list** ptr = &sorted;

        while (*ptr != NULL && ((*ptr)->pdata < current->pdata))
        {
            prev = *ptr;
            ptr = &(*ptr)->next;
        }

        current->next = *ptr;
        if (prev != NULL) {
            prev->next = current;
        }
        else {
            sorted = current;
        }

        current = next;
    }

    head = sorted;
}

void printList(struct list* head) {
    while (head != NULL) {
        printf("%d ", head->pdata);
        head = head->next;
    }
    printf("\n");
}

//----- Итератор сортировки для массива указателей

void Sort(void** pp, int (*pf)(void*, void*)) // array int reference
{
    int i, k;
    do
        for (k = 0, i = 1; pp[i] != NULL; i++)
            if ((*pf)(pp[i - 1], pp[i]) >= 0)                   // вызов функции сравнения
            {
                void* q;                                          // перестановка указателей
                k++; 
                q = pp[i - 1]; 
                pp[i - 1] = pp[i]; 
                pp[i] = q;
            }
    while (k);
}

int cmp_int(void* p1, void* p2)
{
    return *(int*)p1 - *(int*)p2;
}

int str_len(void* p1, void* p2) {
    return (strlen(*(char**)p1) - strlen(*(char**)p2));
}
//reference int array
int b1 = 5, b2 = 6, b3 = 3, b4 = 2;
void* PP[] = { &b1, &b2, &b3, &b4, NULL };

//reference string array
char aC1[] = "aaaa", aC2[] = "bbbbb", aC3[] = "ddd";
char* bC1 = aC1, * bC2 = aC2, * bC3 = aC3; 
void* PPChar[] = { &bC1, &bC2, &bC3, NULL };

void ForEach(struct list* pv, void (*pf)(void*)) {

    for (; pv != NULL; pv = pv->next)

        (*pf)(pv->pdata);

}
void print(void* p) { puts((char*)p); }

struct list* SortStrList(struct list* head)
{
    struct list* sorted = NULL;
    struct list* current = head;

    while (current != NULL) {
        struct list* next = current->next;
        struct list* prev = NULL;
        struct list** ptr = &sorted;

        while (*ptr != NULL && (strlen((*ptr)->pdata) < strlen(current->pdata)))
        {
            prev = *ptr;
            ptr = &(*ptr)->next;
        }

        current->next = *ptr;
        if (prev != NULL) {
            prev->next = current;
        }
        else {
            sorted = current;
        }

        current = next;
    }
    return sorted;
}

void main()
{
    //array int
    Sort(PP, cmp_int);
    for (int i = 0; PP[i] != NULL; i++) printf("%d ", *(int*)PP[i]);

    printf("\n");

    //list int
    insertionSort(PHint);
    printList(PHint);

    printf("\n");

    //list string
    char* pp;
    pp = SortStrList(PH);
    ForEach(pp, print);

    printf("\n");

    //array string
    Sort(PPChar, str_len);
    for (int i = 0; PPChar[i] != NULL; i++) 
    {
        printf("%s\n", *(char**)PPChar[i]);
    }
    puts("");
}