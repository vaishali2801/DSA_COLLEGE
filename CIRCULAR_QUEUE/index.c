#include<stdio.h>
#include<stdlib.h>
#define size 5

int cq[size],rear = -1,front = -1;

// function prototypes
void insert(int data);
int dequeue();
void display();

int main(){
    int choice,data;
    while(1){
        printf("\n\n 1. INSERT");
        printf("\n 2. REMOVE");
        printf("\n 3. DISPLAY");
        printf("\n 4. EXIT");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d",&data);
                insert(data);
                break;

            case 2:
                data = dequeue();
                if(data != -1)
                    printf("\nRemoved data = %d",data);
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice.");
                break;
        }
    }
    return 0;
}

int dequeue(){
    int data;

    if(front == -1){
        printf("\nCircular Queue is Empty!");
        return -1;
    }

    data = cq[front];

    if(front == rear){
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }

    return data;
}

void display(){
    if(front == -1){
        printf("\nCircular Queue is Empty!");
        return;
    }

    printf("\nCircular Queue elements: ");
    int i = front;

    while(i != rear){
        printf("%d ", cq[i]);
        i = (i + 1) % size;
    }
    printf("%d", cq[rear]);
}

void insert(int data){
    if((front == 0 && rear == size-1) || (rear + 1) % size == front){
        printf("\nCircular Queue is Full!");
        return;
    }

    if(front == -1)
        front = 0;

    rear = (rear + 1) % size;
    cq[rear] = data;
}
