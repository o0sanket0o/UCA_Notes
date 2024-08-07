#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>
int sz = 1;
int i = 0;
int *arr;

void alter(int n){
	int* temp = (int*) malloc(sz * sizeof(int));
	for(int a = 0; a < i; ++a) temp[a] = arr[a];
	arr = (int*) malloc (n * (sizeof(int)));
	for(int a = 0; a < i; ++a) arr[a] = temp[a];
	free(temp);
	sz = n;
}

void push(int num){
	if(i == 0 && sz ==1) alter(1);
	if(i == sz) alter(sz * 2);
	arr[i++] = num;
}

int pop(){
	if(i == 0) return INT_MIN;
	int ans = arr[--i];
	if(i < sz / 4) alter(sz / 2);
	return ans;
}
bool isEmpty(){
	return i == 0;
}

int size(){
	return i;
};

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
//        while(i){
//                int curr = pop();
//                printf("%d %d %d\n", curr, sz, i);
//        }
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

