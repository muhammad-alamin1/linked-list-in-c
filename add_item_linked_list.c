#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node
{
    int data;
    Node *next;
};

Node *create_node(int item, Node *next);
Node *prepent(Node *head, int item);

int main()
{
    Node *head, *n1, *n2, *n3;

    n1 = create_node(2247, NULL);
    head = n1;
    //printf("Data -> %d\n", n1->data);

    // return prepent func value and assign head
    head = prepent(head, 2225);

    n2 = head;
    printf("First data -> %d\n", n2->data);

    n3 = n2->next;
    printf("Second data -> %d\n", n3->data);


    return 0;
}

// Create Node
Node *create_node(int item, Node *next)
{
    Node *new_node;
    new_node = (Node *)malloc(sizeof(Node));
    if(new_node == NULL)
    {
        printf("Error! Could not a create new node.");
        exit(1);
    }

    new_node->data = item;
    new_node->next = next;

    return new_node;
}

// add Node starting point
Node *prepent(Node *head, int item)
{
    Node *new_node = create_node(item, head);
    return new_node;
}

// Node add linked list ending pointer
