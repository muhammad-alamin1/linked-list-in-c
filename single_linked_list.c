#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
};

struct Node *create_node(int item, struct Node *next);

int main()
{
    struct Node *n;
    n = create_node(2225, NULL);
    printf("Data = %d\n", n->data);

    return 0;
}

// create node
struct Node *create_node(int item, struct Node *next)
{
    struct Node *new_node;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    if(new_node == NULL)
    {
        printf("Error! Could not create a new node.\n");
        exit(1);
    }

    new_node->data = item;
    new_node->next = next;

    return new_node;
}
