#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *next;
};
struct list *head, *node, *newnode;
struct list *prev;
void Add_First()
{
    newnode = (struct list *)malloc(sizeof(struct list));
    printf("Enter new node data:");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
}
void Add_After_First(){
    if(head == NULL){
        printf("\nList is empty. First node inserted.\n");
        Add_First();
        return;
    }
    newnode = (struct list*)malloc(sizeof(struct list));
    printf("Enter new node data:");
    scanf("%d",&newnode->data);

    newnode->next = head->next;
    head->next = newnode;
}

void Add_At_End()
{
    newnode = (struct list *)malloc(sizeof(struct list));
    printf("Enter new node data:");
    scanf("%d", &newnode->data);

    newnode->next = NULL;
    node = head;
    while (node->next != NULL)
    {
        node = node->next;
    }
    node->next = newnode;
}
void Add_After_specificnode()
{
    int a;
    newnode = (struct list *)malloc(sizeof(struct list));
    printf("Enter new node data:");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    printf("\nAfter which node you wants to insert newnode");
    scanf("%d", &a);
    node = head;
    while (node)
    {
        if (node->data == a)
        {
            newnode->next = node->next;
            node->next = newnode;
            break;
        }
        else
        {
            node = node->next;
        }
    }
}
void Delete_first()
{
    node = head;
    head = node->next;
    free(node);
}
void Delete_last()
{
    prev = head;
    node = head->next;
    while (node)
    {
        if (node->next == NULL)
        {
            prev->next = NULL;
            free(node);
            break;
        }
        else
        {
            prev = prev->next;
            node = node->next;
        }
    }
}
void Delete_specificnode()
{
    int a;
    prev = head;
    node = head->next;
    printf("Enter node data which want to delete :");
    scanf("%d", &a);
    if (prev->data == a)
    {
        head = head->next;
        free(prev);
    }
    else
    {
        while (node)
        {
            if (node->data == a)
            {
                prev->next = node->next;
                free(node);
                break;
            }
            else
            {
                prev = prev->next;
                node = node->next;
            }
        }
    }
}
void display()
{
    node = head;
    while (node)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
int main(){
    head = NULL;
    Add_First();
    Add_After_First();
    display();
    return 0;
}
