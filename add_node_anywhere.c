#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node
{
    int data;
    Node *next;
};

Node *create_node(int item, Node *next);
void linked_list_print(Node *head);
Node *append(Node *head, int item);
void insert(Node *node, int item);

int main(void)
{
    Node *head ;

    head = create_node(77, NULL);
    linked_list_print(head);

    // calling insert func
    insert(head, 11);

    head = append(head, 88);
    linked_list_print(head);

    return 0;
}

// create node
Node *create_node(int item, Node *next)
{
    Node *new_node;

    new_node = (Node *)malloc(sizeof(Node));
    if(new_node == NULL)
    {
        printf("Error! Could not create a new Node.\n");
        exit(1);
    }
    new_node->data = item;
    new_node->next = next;

    return new_node;
}

// print linked list
void linked_list_print(Node *head)
{
    Node *current_node = head;
    while(current_node != NULL)
    {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Node add ending point
Node *append(Node *head, int item)
{
    Node *new_node = create_node(item, NULL);

    if(head == NULL)
        return new_node;

    Node *current_node = head;
    while(current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    current_node->next = new_node;

    return head;
}

// insert -> Add Node anywhere
void insert(Node *node, int item)
{
    Node *new_node = create_node(item, node->next);
    node->next = new_node;
}
