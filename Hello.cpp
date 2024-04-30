#include <stdio.h>

typedef struct list_item {
	int data; // �� ����� ��������� �� ������ �����-�� ������
	struct list_item* next; // ��� � ��� ������ �� ��������� ���������
	struct list_item* prev; // ��� � ��� ������ �� ���������� ���������
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
    //list_item* head = NULL; // ������������� ������ ������ � NULL

    list_item* head1 = NULL; // ������������� ������ ������� ������ � NULL
    list_item* head2 = NULL; // ������������� ������ ������� ������ � NULL

    // ��������� �������� � ������ ������
    InsSort(&head1, 10);
    InsSort(&head1, 20);
    InsSort(&head1, 5);

    // ��������� �������� �� ������ ������
    InsSort(&head2, 4);
    InsSort(&head2, 8);
    InsSort(&head2, 18);

    // ������� ���������� ������
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