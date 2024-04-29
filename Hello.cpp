#include <stdio.h>

typedef struct list_item {
	int data; // �� ����� ��������� �� ������ �����-�� ������
	struct list_item* next; // ��� � ��� ������ �� ��������� ���������
	struct list_item* prev; // ��� � ��� ������ �� ���������� ���������
} list_item;

void InsSort(list_item** ph, int v) {
    list_item* q, * p = new list_item;
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

// ������� ��� ������ ��������� ������
void PrintList(list_item* head) {
    list_item* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    list_item* head = NULL; // ������������� ������ ������ � NULL

    // ��������� �������� � ������
    InsSort(&head, 10);
    InsSort(&head, 20);
    InsSort(&head, 5);
    InsSort(&head, 30);

    // ������� ���������� ������
    PrintList(head);

    return 0;
}