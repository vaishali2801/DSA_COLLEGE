#include <stdio.h>

void toh(int n, char a, char c, char b);  // function declaration

int main(){
    int n;
    printf("enter no. of disc: ");
    scanf("%d", &n);

    toh(n, 'A', 'C', 'B');
    return 0;
}

void toh(int n, char a, char c, char b){
    if(n == 1){
        printf("Move disc from %c to %c\n", a, c);
        return;
    }

    toh(n-1, a, b, c);
    printf("Move disc from %c to %c\n", a, c);
    toh(n-1, b, c, a);
}
