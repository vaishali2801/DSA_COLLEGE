#include <stdio.h>
#include <stdlib.h>
struct dlist {
    struct dlist *prev;
    int data;
    struct dlist *next;
};
struct dlist *head = NULL;
// Insert node at the front
void insert_front() {
    struct dlist *newnode = (struct dlist*)malloc(sizeof(struct dlist));

    printf("Enter new node data: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;

    head = newnode;

    printf("Node inserted at front.\n");
}
// Insert node at the end
void insert_end() {
    struct dlist *newnode = (struct dlist*)malloc(sizeof(struct dlist));
    printf("Enter new node data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;
    }
    struct dlist *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;

    printf("Node inserted at end.\n");
}
// Delete last node
void delete_last() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct dlist *temp = head;

    // Only one node
    if (temp->next == NULL) {
        head = NULL;
        free(temp);
        printf("Last node deleted.\n");
        return;
    }

    // Traverse to last
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);

    printf("Last node deleted.\n");
}

// Delete node before a given position
void delete_before_pos() {
    int pos, i = 1;
    printf("Enter the position before which node should be deleted: ");
    scanf("%d", &pos);

    // Invalid
    if (pos <= 1 || head == NULL || head->next == NULL) {
        printf("Not possible.\n");
        return;
    }

    struct dlist *temp = head;

    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL || temp->prev == NULL) {
        printf("Deletion not possible.\n");
        return;
    }

    struct dlist *del = temp->prev;

    if (del->prev != NULL)
        del->prev->next = temp;
    else
        head = temp;

    temp->prev = del->prev;
    free(del);

    printf("Node deleted before position %d.\n", pos);
}
void display() {
    struct dlist *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly Linked List: ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}
int main() {
    int ch;
    do {
        printf("\n---- DOUBLY LINKED LIST MENU ----\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Delete last node\n");
        printf("4. Delete node before position\n");
        printf("5. Display list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insert_front(); break;
            case 2: insert_end(); break;
            case 3: delete_last(); break;
            case 4: delete_before_pos(); break;
            case 5: display(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (ch != 6);
    return 0;
}
