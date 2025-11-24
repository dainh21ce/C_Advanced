#ifndef __LIST_H
#define __LIST_H
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node_t;

void printAllNode(Node_t *head);
Node_t *creatNode(int data_t);
void pushHead(Node_t **head, int val);
bool pushAt(Node_t *head, int data, int pos);
#endif
