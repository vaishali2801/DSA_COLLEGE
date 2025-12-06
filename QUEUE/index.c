#include<stdio.h>
#include<stdlib.h>
#define size 5

int q[size],rear = -1,front = -1;

void insert(int data){
    if(rear == (size-1)){
        printf("\n queue is overflow");
    }else{
        if(rear == -1 && front == -1){
            rear = front = 0;
            q[rear] = data;
        }else{
            rear++;
            q[rear] = data;
        }
    }
}
int remove(){
    int data;
    if(rear == -1 && front == -1){
        printf("queue is empty");
        return -1;
    }else{
        if(rear == front){
            data = q[front];
            rear = front = -1;
        }else{
            data = q[front];
            front++;
        }
    }
    return data;
}
void display(){
    if(rear == -1 && front == -1){
        printf("queue is Empty");
    }
    
    for(int i = front;i<= rear;i++){
        printf("%d",q[i]);
    }
}
int main(){
    int ch,data;
    while(1){
        printf("\n 1.INSERT");
        printf("\n 2.DELETE");
        printf("\n 3.DISPLAY");
        printf("\n 4.EXIT");

        printf("\n Enter your choice :");
        scanf("%d",&ch);

        switch(ch){
            case 1: 
                printf("Enter data:");
                scanf("%d",&data);

                insert(data);
                break;
            case 2:
                data = remove();
                printf("\n deleted data = %d",data);
                break;
            case 3:
                display();
                break;
            case 4:exit(1);
                break;
            default:
                printf("\n invalid choice");
                break;                
        }
    }
    return 0;
}