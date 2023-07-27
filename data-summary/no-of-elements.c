// Implementation of mean in linked lists

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *create_node(int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_node(node **head, int data)
{
    node *new_node = create_node(data);
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}

void get_count(node **head)
{
    node *current = *head;
    int count = 0;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    printf("Count is: %d\n", count);
}

void print_list(node **head)
{
    node *current = *head;
    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
}

int main()
{
    printf("Enter the number of elements: ");
    node *head = NULL;
    int n;
    scanf("%d", &n);
    while (n > 0)
    {
        int data;
        scanf("%d", &data);
        insert_node(&head, data);
        n--;
    }
    printf("\nCalculating number of elements for below list\n");
    print_list(&head);
    printf("NULL\n\n");
    get_count(&head);
    return 0;
}