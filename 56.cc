struct ListNode{
	int value;
	ListNode* next;
	};
ListNode* MeetingNode(ListNode* head)
{
	if(head==nullptr)return nullptr;
	ListNode* slow = head->next;
	if(slow==nullptr)return nullptr;
	ListNode* fast = slow->next;
	while(fast!=nullptr&&slow!=nullptr)
	{
		if(fast==slow)return fast;
		slow = slow->next;
		fast = fast->next;
		if(fast!=nullptr)fast = fast->next;
	}
	return nullptr;
}
ListNode* EntryNodeOfLoop(ListNode* head)
{
	ListNode* meet = MeetingNode(head);
	if(meet==nullptr)return nullptr;
	
	int nodeinloop = 1;
	ListNode* t = meet;
	while(t->next!=meet)
	{
		t = t->next;
		nodeinloop++;
	}
	
	t = head;
	for(int i =0;i<nodeinloop;i++)
	{
		t = t->next;
	}
	ListNode* t2 = head;
	while(t2!=t)
	{
		t = t->next;
		t2 = t2->next;
	}
	return t;
}
