#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Node{
    int num;
    struct Node* next;
}ListNode;

ListNode* head = NULL;
int n = 0;

int size(){
    return n;
}
bool isEmpty(){
    return n == 0;
}
void push(int x){
    ++n;
    if(!head){
        head = (ListNode*) malloc (sizeof(ListNode));
        head -> num = x;
        ListNode* temp = (ListNode*) malloc (sizeof(ListNode));
        temp -> num = -1; 
        temp -> next = head;
        head = temp;
    }else{
        head -> num = x;
        ListNode* nextNode = (ListNode*) malloc (sizeof(ListNode));
        nextNode -> num = -1;
        nextNode -> next = head;
        head = nextNode;
    }
}
int pop(){
    while(head && head -> num == -1) head = head -> next;
    if(!head || n == 0) return -1; 
    int ans = head -> num;
    head = head -> next;
    --n;
    return ans;
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
	assert(pop() == -1);
	assert(isEmpty() == true);
	printf("Code executed successfully.\n");
}



int main(){
    test();
    
    
    return 0;
}
