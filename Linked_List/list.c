#include <stdio.h>
#include "list.h"
#include <stdlib.h>
#include <stdbool.h>

// Khoi tạo 1 node
Node_t *creatNode(int data_t)
{
    // Moi khi tao node tan cap phat dong
    Node_t *temp = malloc(sizeof(Node_t));
    temp->data = data_t;
    temp->next = NULL;
    return temp;
}

// THem 1 node mới vào đầu danh sách
//  B > A
void pushHead(Node_t **head, int val)
{
    Node_t *_temp = creatNode(val);
    if (*head == NULL)
    {
        *head = _temp;
    }
    else
    {
        _temp->next = *head;
        *head = _temp;
    }
}

// Thêm 1 node mới ở vị trí bất kì
// pos đếm từ 0
bool pushAt(Node_t *head, int data, int pos)
{
    Node_t *pt = head;
    int i = 0;
    while (pt != NULL && i != pos - 1)
    {
        pt = pt->next;
        i++;
    }

    if (i != pos - 1)
    {
        return false;
    }
    else
    {
        Node_t *temp = creatNode(data);
        temp->next = pt->next;
        pt->next = temp;
    }
    return true;
}