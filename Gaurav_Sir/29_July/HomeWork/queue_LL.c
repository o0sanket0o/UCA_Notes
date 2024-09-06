#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Node{
    int num;
    struct Node* next;
}ListNode;

ListNode* head = NULL;
ListNode* temp = NULL;
int n = 0;

bool isEmpty(){
    return n == 0;
}
int getSize(){
    return n;
    
}

void push(int x){
    if(head == NULL){
        head = (ListNode*) malloc (sizeof(ListNode));
        head -> num = x;
        n = 1;
        temp = (ListNode*) malloc (sizeof(ListNode));
        temp -> num = -1;
        head -> next = temp;
    }else{
        temp -> num = x;
        ListNode* nextNode = (ListNode*) malloc (sizeof(ListNode));
        nextNode -> num = 0;
        temp -> next = nextNode;
        temp = temp -> next;
        ++n;
    }
}
int pop(){
    if(!head || n == 0) return -1;
    int ans = head -> num;
    head = head -> next;
    --n;
    // if(head) printf("Head's value is %d.\n",ans);
    return ans;
}

void test(){
    push(3);
	push(1);
	push(4);
	push(2);
	assert(pop() == 3);
	assert(pop() == 1);
	assert(pop() == 4);
	assert(pop() == 2);


	assert(isEmpty() == true);
	assert(getSize() == 0);
	push(10);
	assert(isEmpty() == false);
	assert(getSize() == 1);
	assert(pop() == 10);
	for (int i = 0; i < 10; i++) {
		push(i);
	}
	for (int i = 0; i <= 9; i++) {
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
    
}


int main() {
    test();
    
    return 0;
}
