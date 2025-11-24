#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;


// Insert at front
void insertFront() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter new node data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;

    printf("Node inserted at front.\n");
}


// Insert at end
void insertEnd() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter new node data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;

    printf("Node inserted at end.\n");
}


// Insert node in ASCENDING ORDER
void insertAscending() {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter new node data: ");
    scanf("%d", &newnode->data);

    if (head == NULL || newnode->data < head->data) {
        newnode->next = head;
        head = newnode;
        return;
    }

    struct node *temp = head;
    while (temp->next != NULL && temp->next->data < newnode->data) {
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    printf("Node inserted in ascending order.\n");
}


// Delete first node
void deleteFirst() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;
    head = head->next;
    free(temp);

    printf("First node deleted.\n");
}


// Delete before position
void deleteBeforePos() {
    int pos;
    printf("Enter position before which node is to be deleted: ");
    scanf("%d", &pos);

    if (pos <= 1 || head == NULL || head->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 2) {
        deleteFirst();
        return;
    }

    struct node *temp = head;
    struct node *prev = NULL;
    int i = 1;

    while (i < pos - 1 && temp != NULL) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Node before position %d deleted.\n", pos);
}


// Delete after position
void deleteAfterPos() {
    int pos;
    printf("Enter position after which node is to be deleted: ");
    scanf("%d", &pos);

    struct node *temp = head;
    int i = 1;

    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Deletion not possible.\n");
        return;
    }

    struct node *del = temp->next;
    temp->next = del->next;
    free(del);

    printf("Node deleted after position %d.\n", pos);
}


// Display list
void display() {
    struct node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d → ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


// Main Menu
int main() {
    int ch;

    do {
        printf("\n---- MENU ----\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert in ascending order\n");
        printf("4. Delete first node\n");
        printf("5. Delete before position\n");
        printf("6. Delete after position\n");
        printf("7. Display list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insertFront(); break;
            case 2: insertEnd(); break;
            case 3: insertAscending(); break;
            case 4: deleteFirst(); break;
            case 5: deleteBeforePos(); break;
            case 6: deleteAfterPos(); break;
            case 7: display(); break;
            case 8: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (ch != 8);

    return 0;
}