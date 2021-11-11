#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node
{
    int data;
    Node *next;
    Node *prev;
};

Node *create_node(int item, Node *next, Node *prev);
void print_linked_list(Node *head);
Node *prepent(Node *head, int item);
Node *append(Node *head, int item);
Node *remove_node(Node *head, Node *node);
void insert(Node *node, int item);

int main(void)
{
    Node *head, *n1;

    head = create_node(25, NULL, NULL);
    print_linked_list(head);

    // insert
    insert(head, 90);
    print_linked_list(head);

    n1 = prepent(head, 55);
    head = n1;
    print_linked_list(head); // Add node starting point

    head = append(head, 78);
    print_linked_list(head);

    head = remove_node(head, n1);
    print_linked_list(head);

    return 0;
}

// create node
Node *create_node(int item, Node *next, Node *prev)
{
    Node *new_node;

    new_node = (Node *)malloc(sizeof(Node));
    if(new_node == NULL)
    {
        printf("Error! Could not create a new node.\n");
        exit(1);
    }

    new_node->data = item;
    new_node->next = next;
    new_node->prev = prev;

    return new_node;
}

// print doubly linked list
void print_linked_list(Node *head)
{
    Node *current_node = head;

    while(current_node != NULL)
    {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// prepend -> Add node doubly linked list starting point
Node *prepent(Node *head, int item)
{
    Node *new_node = create_node(item, head, NULL);

    new_node->next->prev = new_node;
    return new_node;
}

// append -> Add node doubly linked list ending point
Node *append(Node *head, int item)
{
    Node *new_node = create_node(item, NULL, NULL);

    if(head == NULL)
        return new_node;

    Node *current_node = head;
    while(current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    current_node->next = new_node;
    new_node->prev = current_node;

    return head;
}

// remove node
Node *remove_node(Node *head, Node *node)
{
    if(head == node)
    {
        head = node->next;
        head->prev = NULL;
        free(node);
        return head;
    }

    Node *previous_node = node->prev;
    Node *next_node = node->next;

    previous_node->next = next_node;
    next_node->prev = previous_node;

    free(node);
    return head;
}

// Node add anywhere
void insert(Node *node, int item)
{
    Node *new_node = create_node(item, node->next, node->prev);

    new_node->next = node->next;
    node->next = new_node;
}
