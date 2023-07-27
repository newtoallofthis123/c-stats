// Implementing the median function

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *create_node(int data) {
    node *new_node = (node *) malloc(sizeof(node));
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

void print_list(node **head)
{
    node *current = *head;
    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
}

void arrange_ascending(node **head){
    node *current = *head;
    while (current != NULL){
        node *next = current->next;
        while (next != NULL){
            if (current->data > next->data){
                int temp = current->data;
                current->data = next->data;
                next->data = temp;
            }
            next = next->next;
        }
        current = current->next;
    }
}

int get_median(node **head){
    node *current = *head;
    int count = 0;
    while (current != NULL){
        count++;
        current = current->next;
    }
    current = *head;
    int mid = count / 2;
    if (count % 2 == 0){
        int i = 0;
        while (i < mid - 1){
            current = current->next;
            i++;
        }
        return (current->data + current->next->data) / 2;
    }
    else{
        int i = 0;
        while (i < mid){
            current = current->next;
            i++;
        }
        return current->data;
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
    printf("\nCalculating mean for below list\n");
    print_list(&head);
    printf("NULL\n\n");
    arrange_ascending(&head);
    printf("Media of the given data is: %d", get_median(&head));
    return 0;
}