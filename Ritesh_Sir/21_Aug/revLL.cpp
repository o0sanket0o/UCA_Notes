struct Node* rev(struct Node* head, struct Node* prev){
	if(head -> next == NULL){
		head -> next = prev;
		return head;
	}
	struct Node* nextNode = head -> next;
	head -> next = prev;
	return rev(nextNode, head);
}
struct Node* reverseList(struct Node* head) {
	return rev(head, NULL);
}
