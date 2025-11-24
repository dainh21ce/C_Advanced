#include <stdio.h>
#include "list.h"
#include <stdlib.h>

// In all Node
void printAllNode(Node_t *head)
{
    Node_t *pt = head;
    while (pt != NULL)
    {
        printf("Data: %d\n", pt->data);
        pt = pt->next;
    }
}

int main()
{
    // Node_t *head = malloc(sizeof(Node_t)); // “head là con trỏ kiểu Node_t*, được cấp phát động để chứa 1 struct Node_t.”
    // Node_t *second = malloc(sizeof(Node_t));
    // Node_t *third = malloc(sizeof(Node_t));

    // head->data = 10;
    // head->next = second;

    // second->data = 20;
    // second->next = third;

    // third->data = 30;
    // third->next = NULL;

    Node_t *head = NULL;
    head = creatNode(1);
    pushHead(&head, 2);
    pushAt(head, 3, 1);
    printAllNode(head);
    return 0;
}