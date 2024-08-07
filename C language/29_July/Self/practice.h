#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

struct Node{
	int item;
	struct Node* next;
};

int N = 0;
struct Node* head = NULL;

void push(int item){
	struct Node* newHead = (struct Node*) malloc (sizeof(struct Node));
	newHead -> item = item;
	N++;
	struct Node* temp = head;
	head = newHead;
	head -> next = temp;
}

int pop(){
	if(N == 0) return INT_MIN;
	int curr = head -> item;
	struct Node* temp = head;
	head = head -> next;
	free(temp);
	N--;
	return curr;
}
bool isEmpty(){
	return N == 0;
}

int size(){
	return N;
}

void test(){
push(10);
push(20);
push(30);

assert(pop() == 30);
assert(size() == 2);
assert(isEmpty() == false);

assert(pop() == 20);
assert(size() == 1);
assert(isEmpty() == false);

assert(pop() == 10);
assert(size() == 0);
assert(isEmpty() == true);
}
