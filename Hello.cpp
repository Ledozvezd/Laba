#include <stdio.h>

typedef struct list_item {
	int data; // по этому указателю мы храним какие-то данные
	struct list_item* next; // это у нас ссылка на следующий указатель
	struct list_item* prev; // это у нас ссылка на предыдущий указатель
} list_item;

void InsSort(list_item** ph, int v) {
    list_item* q, *p = new list_item;
    p->data = v;
    p->prev = p->next = NULL;
    if (*ph == NULL) {
        *ph = p; return;
    }
    for (q = *ph; q != NULL && v > q->data; q = q->next);
    if (q == NULL) {
        for (q = *ph; q->next != NULL; q = q->next);
        p->prev = q;
        q->next = p;
        return;
    }
    p->next = q;
    p->prev = q->prev;
    if (q->prev == NULL)
        *ph = p;
    else
        q->prev->next = p;
    q->prev = p;
}

// Функция для вывода элементов списка
void PrintList(list_item* head) {
    list_item* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    //list_item* head = NULL; // Устанавливаем голову списка в NULL

    list_item* head1 = NULL; // Устанавливаем голову первого списка в NULL
    list_item* head2 = NULL; // Устанавливаем голову второго списка в NULL

    // Вставляем элементы в первый список
    InsSort(&head1, 10);
    InsSort(&head1, 20);
    InsSort(&head1, 5);

    // Вставляем элементы во второй список
    InsSort(&head2, 4);
    InsSort(&head2, 8);
    InsSort(&head2, 18);

    // Выводим содержимое списка
    PrintList(head1);
    PrintList(head2);

    //list_item* curent = NULL;
    list_item* q = head1;
    list_item* p = head2;
    while (q != NULL || p != NULL)
    {
        InsSort(&head1, p->data);
        q = q->next;
        p = p->next;
    }

    PrintList(head1);
    //list_item = 
    return 0;
}