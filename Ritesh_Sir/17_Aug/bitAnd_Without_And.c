#include <stdio.h>

int bitAnd(int a, int b){
        return ~(~a | ~b);
}

int main(){
        int n1, n2;
        printf("Enter first number:");
        scanf("%d", &n1);
        printf("Enter second number:");
        scanf("%d", &n2);
        int ans = ~(~n1 | ~n2);
        printf("BitWise and of to numbers is:%d.\n", bitAnd(n1, n2));
        printf("Actual and is:%d.\n", n1 & n2);
        return 0;
}

