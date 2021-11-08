#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node
{
    int data;
    Node *next;
};

Node *create_node(int item, Node *next);
void print_linked_list(Node *head);
Node *prepend(Node *head, int item);
Node *append(Node *head, int item);

int main()
{
    Node *head, *n1;

    n1 = create_node(2247, NULL);
    head = n1;
    print_linked_list(head);

    head = prepend(head, 23);
    print_linked_list(head);

    head = append(head, 29);
    print_linked_list(head);

    return 0;
}

// create list
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

// Add Node ending point
Node *append(Node *head, int item)
{
    Node *new_node = create_node(item, NULL);

    if(head == NULL)
    {
        return new_node;
    }

    Node *current_node = head;
    // Append function time complexity O(n)
    while(current_node->next != NULL)
    {
        current_node = current_node->next;
    }

    current_node->next = new_node;
    return head;
}

// print linked list
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

// prepend
Node *prepend(Node *head, int item)
{
    Node *new_node = create_node(item, head);
    return new_node;
}
