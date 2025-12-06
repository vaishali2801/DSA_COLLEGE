#include<stdio.h>
#include<stdlib.h>
#define size 50

char infix[size], postfix[size], stack[size];
int top = -1;

void push(char symbol);
char pop();
int getPrec(char symbol);
void infix_to_postfix();

int main() {
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    infix_to_postfix();
    
    printf("Postfix expression: %s\n", postfix);
    return 0;
}

void infix_to_postfix(){
    int i = 0, p = 0;
    char symbol;

    while(infix[i] != '\0'){

        if(infix[i] != ' ' && infix[i] != '\t'){

            switch(infix[i]){

                case '(':
                    push(infix[i]);
                    break;

                case ')':
                    while((symbol = pop()) != '('){
                        postfix[p++] = symbol;
                    }
                    break;

                case '+':
                case '-':
                case '*':
                case '/':
                case '%':
                case '^':
                    while(top != -1 && getPrec(infix[i]) <= getPrec(stack[top])){
                        postfix[p++] = pop();
                    }
                    push(infix[i]);
                    break;

                default:
                    postfix[p++] = infix[i];
            }
        }
        i++;
    }

    while((symbol = pop()) != '\0'){
        postfix[p++] = symbol;
    }

    postfix[p] = '\0';
}

void push(char symbol){
    if(top == size-1){
        printf("\nStack overflow!");
    }
    else{
        stack[++top] = symbol;
    }
}

char pop(){
    if(top == -1){
        return '\0';
    }
    else{
        return stack[top--];
    }
}

int getPrec(char symbol){
    switch(symbol){
        case '+':
        case '-': return 1;

        case '*':
        case '/':
        case '%': return 2;

        case '^': return 3;

        case '(': return 0;
    }
    return -1;
}
