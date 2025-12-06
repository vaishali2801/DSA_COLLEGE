#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 5

int stack[size];
int top = -1;

void push(){
    int data;
    if(top == size-1){
        printf("\nStack overflow!");
    }else{
        printf("\nEnter the data: ");
        scanf("%d",&data);
        stack[++top] = data;
    }
}

int pop(){
    if(top == -1){
        printf("\nStack is empty!");
        return -1;
    }else{
        return stack[top--];
    }
}

void peek(){
    if(top == -1){
        printf("\nStack is empty!");
    }else{
        printf("\nTop element is: %d",stack[top]);
    }
}

void display(){
    if(top == -1){
        printf("\nStack is empty!");
    }else{
        printf("\nStack elements:");
        for(int i = top; i >= 0; i--){
            printf("\n%d", stack[i]);
        }
    }
}

int main(){
    int choice, data;
    while(1){
        printf("\n\n--- STACK MENU ---");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. PEEK");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                push();
                break;

            case 2:
                data = pop();
                if(data != -1)
                    printf("\nPopped element = %d", data);
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("\nInvalid choice!");
        }
    }
}
