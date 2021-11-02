// Traverse Linked List
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct Node *next;
} Node;

int main()
{
    Node *a = NULL;
    Node *b = NULL;
    Node *c = NULL;

    a = (struct Node*)malloc(sizeof(Node));
    b = (struct Node*)malloc(sizeof(Node));
    c = (struct Node*)malloc(sizeof(Node));

    a->data = 11;
    b->data = 13;
    c->data = 15;

    a->next = b;
    b->next = c;
    c->next = NULL;

    while(a != NULL)
    {
        printf("%d -> ", a->data);
        a = a->next;
    }

    return 0;
}
