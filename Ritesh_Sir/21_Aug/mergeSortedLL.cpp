ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	ListNode* begin;
	if(list1==NULL){
		return list2;
	}
	if(list2==NULL){
		return list1;
	}
	if((list1->val) < (list2->val)){
		begin=list1;
		list1=list1->next;
	}else{
		begin=list2;
		list2=list2->next;
	}
	ListNode* ans=begin;
	while(list1!=NULL && list2!=NULL){
		if(list1->val<list2->val){
			begin->next=list1;
			begin=begin->next;
			list1=list1->next;
		}else{
			begin->next=list2;
			begin=begin->next;
			list2=list2->next;
		}
	}
	while(list1!=NULL){
		begin->next=list1;
		begin=begin->next;
		list1=list1->next;
	}
	while(list2!=NULL){
		begin->next=list2;
		begin=begin->next;
		list2=list2->next;
	}
	return ans;
}
