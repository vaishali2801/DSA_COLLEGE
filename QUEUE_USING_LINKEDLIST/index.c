#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int data;
    struct Queue *next;
};

struct Queue *rear = NULL;
struct Queue *front = NULL;

void insert() {
    struct Queue *temp;
    temp = (struct Queue *)malloc(sizeof(struct Queue));

    printf("\nEnter new value: ");
    scanf("%d", &temp->data);

    temp->next = NULL;

    // If queue is empty
    if (rear == NULL && front == NULL) {
        rear = temp;
        front = temp;
    } else {
        rear->next = temp;
        rear = rear->next;
    }

    printf("\nInserted successfully!\n");
}

int removeData() {
    int data;
    struct Queue *temp;

    if (front == NULL && rear == NULL) {
        printf("\nQueue is empty!\n");
        return -1;
    } else {
        // Only one element
        if (front->next == NULL) {
            temp = front;
            data = front->data;
            front = NULL;
            rear = NULL;
            free(temp);
            return data;
        } else {
            temp = front;
            data = front->data;
            front = front->next;
            free(temp);
            return data;
        }
    }
}

void display() {
    struct Queue *temp;

    if (rear == NULL || front == NULL) {
        printf("\nQueue is empty!\n");
    } else {
        printf("\nQueue Elements:\n");
        temp = front;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int ch, data;

    while (1) {
        printf("\n---- Queue Menu ----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            insert();
            break;

        case 2:
            data = removeData();
            if (data != -1)
                printf("\nDeleted value: %d\n", data);
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("\nInvalid choice!\n");
        }
    }

    return 0;
}
