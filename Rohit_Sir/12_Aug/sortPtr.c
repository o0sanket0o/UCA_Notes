#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

int compareAsc(int a, int b){
    return a > b;
}
int compareDesc(int a, int b){
    return a < b;
}
void swap(int i, int j,int *arr){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void sort(int n, int *arr, int (*cmp)(int, int)){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(cmp(arr[i], arr[j])) swap(i, j, arr);
        }
    }
}

void print(int n, int *arr){
    for(int i = 0; i < 10; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int n = 10;
    int *arr = (int*) malloc(10 * sizeof(int));
    srand(time(NULL));
    for(int i = 0; i < 10; i++) arr[i] = rand() % 20;
    print(n, arr);
    sort(n, arr, compareDesc);
    print(n, arr);
    sort(n, arr, compareAsc);
    print(n, arr);
    return 0;
}
