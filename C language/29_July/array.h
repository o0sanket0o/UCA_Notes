#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int ind = 0;
int N = 1;
int* arr;

void resize(int sz){
        // printf("Resize is called for %d\n",sz);
        if(sz < 0) return;
        int* brr = (int*) malloc(sz * sizeof(int));
        for(int i = 0; i < sz; i++) brr[i] = arr[i];
        int* temp = arr;
        arr = brr;
        free(temp);
        // printf("\nN = %d\n", N);
        //for(int i = 0; i < sz; i++) printf("%d ",arr[i]);
        // printf("\n");
        N = sz;
}

void push(int item){
        if(ind == N) resize(2 * N);
        if(N == 1 && ind == 0) arr = (int*) malloc (N * sizeof(int)); 
        // printf("%d and %d.\n", ind, item);
        // printf("Pushed %d\n", item);
        arr[ind++] = item;
}


int pop(){
        if(ind == 0) return INT_MIN;
        int ans = arr[--ind];
        if(ind < N/4) resize(N/2);
        // printf("Removed %d\n", ans);
        return ans;
}

bool isEmpty(){
        return ind == 0;
}
int size(){
	return ind;
}
void test(){
        push(10);
        push(23);
        push(19);
        push(120);
        push(8);
        push(5);
        push(12);
        push(100);
        push(13);
        push(-23);
       // while(ind){
       //         int curr = pop();
       //         printf("%d %d %d\n", curr, N, ind);
       // }
	assert(pop() == -23);
	assert(isEmpty() == false);
	assert(size() == 9);
	assert(pop() == 13);
	assert(size() == 8);
	assert(isEmpty() == false);
	assert(pop() == 100);
	assert(size() == 7);
	assert(isEmpty() == false);
	assert(pop() == 12);
	assert(size() == 6);
	assert(isEmpty() == false);
	assert(pop() == 5);
	assert(size() == 5);
	assert(isEmpty() == false);
	assert(pop() == 8);
	assert(size() == 4);
	assert(isEmpty() == false);
	assert(pop() == 120);
	assert(size() == 3);
	assert(isEmpty() == false);
	assert(pop() == 19);
	assert(isEmpty() == false);
	assert(size() == 2);
	assert(pop() == 23);
	assert(isEmpty() == false);
	assert(size() == 1);
	assert(pop() == 10);
	assert(size() == 0);
	assert(isEmpty() == true);
	assert(pop() == INT_MIN);
	assert(isEmpty() == true);
}
