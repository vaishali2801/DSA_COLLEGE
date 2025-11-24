#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void insert_End(int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Node inserted at end.\n");
}
void insert_Before_Pos(int value, int pos) {
    struct Node *newNode = createNode(value);
    if (pos == 1) {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
        printf("Node inserted before position 1.\n");
        return;
    }
    struct Node *temp = head;
    int i;
    for (i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted before position %d.\n", pos);
}
void delete_First() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    if (head->next == head) {
        head = NULL;
        free(temp);
    } else {
        struct Node *last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next;
        last->next = head;
        free(temp);
    }
    printf("First node deleted.\n");
}
void delete_After_Pos(int pos) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    int i;
    for (i = 1; i < pos && temp->next != head; i++) {
        temp = temp->next;
    }
    struct Node *delNode = temp->next;
    temp->next = delNode->next;
    if (delNode == head) {
        head = head->next;
    }
    free(delNode);
    printf("Node after position %d deleted.\n", pos);
}
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
int main() {
    int choice, value, pos;
    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at end\n");
        printf("2. Insert before position\n");
        printf("3. Delete first node\n");
        printf("4. Delete after position\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert_End(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insert_Before_Pos(value, pos);
                break;
            case 3:
                delete_First();
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &pos);
                delete_After_Pos(pos);
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
