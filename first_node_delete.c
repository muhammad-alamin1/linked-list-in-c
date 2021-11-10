#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node
{
    int data;
    Node *next;
};

Node *create_node(int item, Node *next);
void print_list(Node *head);
Node *remove_node(Node *head, Node *node);
Node *prepent(Node *head, int item);

int main(void)
{
    Node *head, *n1, *n2;

    n1 = create_node(65, NULL);
    head = n1;
    print_list(head);

    n2 = prepent(head, 67);  // Add node first position
    head = n2;
    print_list(head);

    head = remove_node(head, n1); // Remove first node
    print_list(head);

    return 0;
}

// create node
Node *create_node(int item, Node *next)
{
    Node *new_node;

    new_node = (Node *)malloc(sizeof(Node));
    if(new_node == NULL)
    {
        printf("Error! Could not create a new node.");
        exit(1);
    }

    new_node->data = item;
    new_node->next = next;
}

// print
void print_list(Node *head)
{
    Node *current_node;

    current_node = head;
    while(current_node != NULL)
    {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// remove node first position
Node *remove_node(Node *head, Node *node)
{
    if(node == head)
    {
        head = node->next;
        free(node);
        return head;
    }

    Node *current_node = head;
    while(current_node != NULL)
    {
        if(current_node->next == node)
            break;
        else
            current_node = current_node->next;
    }

    if(current_node == NULL)
        return head;

    current_node->next = node->next;
    free(node);

    return head;
}

// prepent
Node *prepent(Node *head, int item)
{
    Node *new_node = create_node(item, head);
    return new_node;
}
