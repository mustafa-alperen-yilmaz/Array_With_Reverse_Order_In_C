#include <stdio.h>
#include <stdlib.h>

typedef struct tagSingleLinkedList {
    int data;
    struct tagSingleLinkedList* next;
    }SLLI;

void PrintList(SLLI* head){
    while(NULL != head) {
        printf("Data : %d\n", head->data);
        head = head->next;
    }

}
SLLI* AddItemToEnd(SLLI* head, int dataToAdd){
    SLLI* last;

    SLLI* pItem = (SLLI*) malloc(sizeof(SLLI));
    if (NULL == pItem) {
        printf("Cannot allocate memory for the new item!!!\n");
        exit(1);
    }

    pItem->data = dataToAdd;

    pItem->next = NULL;



    if (NULL == head)
        return pItem;

	last = head;
	while (NULL != last->next)
        last = last->next;

    last->next = pItem;

    return head;
}

void nastedLoop(SLLI** head){
    SLLI* prev = NULL;
    SLLI* current = *head;
    SLLI* next = NULL;
      while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    PrintList(head);
}
 int main()
{
    SLLI* head = NULL;
    int i;

    for (i = 10; i > 0; --i)
        head = AddItemToEnd(head, i);


    printf("Print list...\n");
    PrintList(head);
    printf("----------------------------------\n");
    nastedLoop(*&head);
    return 0;
}
