#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


int n = 1;
int sz = 1;
int* arr;


void swap(int a, int b, int *arr){
	// printf("Swap %d and %d\n", a, b);
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void modifySize(int s){
	// printf("Modify size called for %d.\n", s);
	if(s == 2){
		arr = (int *) malloc (8);
		sz = s;
		return;
	} 
	int *brr = (int *) malloc (s * sizeof(int));
	for(int i = 0; i < s ; i++) brr[i] = arr[i];
	arr = brr;
	sz = s;
}

void swim(int ind){
	// printf("Swim for ind = %d:\n", ind);
	while(ind > 1){
		int prnt = ind / 2;
		// printf("prnt is %d and ind is %d .....",arr[prnt], arr[ind]);
		if(arr[prnt] < arr[ind]){
			swap(prnt, ind, arr);
			ind = prnt;
		}
		else break;
	}
	// printf("\n");
}

void sink(int ind){
	while(ind < n){
		int temp = ind;
		int l = 2 * ind, r = 2 * ind + 1;
		if(l < n && arr[l] > arr[temp]) temp = l;
		if(r < n && arr[r] > arr[temp]) temp = r;
		if(temp == ind) break;
		swap(ind, temp, arr);
		sink(temp);
	}
}

void push(int x){
	if(n == sz) modifySize(sz * 2);
	arr[n] = x;
	// printf("Value of %d index is %d.\n", n, x);
	swim(n);
	++n;
	// printf("n = %d\n", n);
}



int getSize(){
	return n - 1;
}
bool isEmpty(){
	return n <= 1;
}

int pop(){
	if(n == 1) return -1;
	int ans = arr[1];
	arr[1] = arr[n];
	sink(1);
	--n;
	if(n < sz / 4) modifySize(sz / 2);
	return ans;
}

int main(){
	push(3);
	push(1);
	push(4);
	push(2);
	assert(pop() == 4);
	assert(pop() == 3);
	assert(pop() == 2);
	assert(pop() == 1);


	assert(isEmpty() == true);
	assert(getSize() == 0);
	push(10);
	assert(isEmpty() == false);
	assert(getSize() == 1);
	assert(pop() == 10);
	for (int i = 0; i < 10; i++) {
		push(i);
	}
	for (int i = 9; i >= 0; i--) {
		assert(pop() == i);
	}

	// Test case 5: Edge case - pop from empty heap
	assert(pop() == -1);
	push(5);
	push(5);
	push(3);
	push(3);
	assert(pop() == 5);
	assert(pop() == 5);
	assert(pop() == 3);
	assert(pop() == 3);


	printf("Code is successfully executed.\n");
	return 0;
}


