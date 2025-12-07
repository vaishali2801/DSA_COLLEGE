#include<stdio.h>
#include<stdlib.h>
#define size 5

int cq[size],rear = -1,front = -1;
int Delete(){
    int data;
    if(front == -1){
        printf("\nCircular Queue is Empty!");
        return -1;
    }else{
        data = cq[front];
        if(front == rear){
            front = rear = -1;
        }else if(front == size -1){
            front =0;
        }else{
            front++;
        }
        return data;
    }
}
void display(){
    if(front == -1){
        printf("\nCircular Queue is Empty!");
        return;
    }
    printf("\nCircular Queue elements: ");
    if(front<= rear){
        for(int i = front;i<=rear;i++){
            printf("%d",cq[i]);
        }
    }else{
        for(int i = front;i<=rear;i++){
            printf("%d",cq[i]);
        }
        for(int i = front;i<size;i++){
            printf("%d",cq[i]);
        }
    }
    printf("\n");
}
void insert(int data){
    if((front == 0 && rear == size-1) || (rear + 1) == front){
        printf("\nCircular Queue is Full!");
    }else{
        if(front == -1 && rear == -1){
            front = rear = 0;
        }else if(rear == size-1 && front!=0){
            rear = 0;
        }else{
            rear++;
        }
        cq[rear] = data;
    }
}
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
                data = Delete();
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