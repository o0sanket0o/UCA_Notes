#include <stdio.h>
#include <stdlib.h>
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int callAny(int (*fun)(int, int), int a, int b);

int add(int a, int b){
    return a + b;
}
int mul(int a, int b){
    return a * b;
}
int divide(int a, int b){
    return a / b;
}
int sub(int a, int b){
    return a - b;
}
int callAny(int (*fun)(int, int), int a, int b){
    return fun(a, b);
}
int main() {
    int callAny(int (*fun)(int, int) , int a, int b);
    printf("%d\n", callAny(add, 15, 20));
    printf("%d\n", callAny(sub, 25, 10));
    printf("%d\n", callAny(mul, 25, 10));
    printf("%d\n", callAny(divide, 25, 10));
    
    return 0;
}
