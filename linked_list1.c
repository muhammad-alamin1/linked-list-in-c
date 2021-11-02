#include <stdio.h>
#include <stdlib.h>

struct Node *create_linked_list(int arr[], int size);

typedef struct
{
    int data;
    struct Node *next;
} Node;

int main()
{
    int a[] = {5, 11, 19};
    int n = sizeof(a)/sizeof(a[0]);

    Node *head;
    head = create_linked_list(a, n);
    while(head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");

    return 0;
}

struct Node *create_linked_list(int arr[], int size)
{
    Node *head = NULL, *temp = NULL, *current = NULL;

    int i;
    for(i = 0; i < size; i++)
    {
        temp = (struct Node *)malloc(sizeof(Node));
        temp->data = arr[i];
        temp->next = NULL;
        if(head == NULL)
        {
            head = temp;
            current = temp;
        }
        else
        {
            current->next = temp;
            current = current->next;
        }
    }
    return head;
}
