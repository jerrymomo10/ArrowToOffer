struct ListNode{
	int value;
	ListNode* next;
	};
void deleteDuplication(ListNode** head)
{
	if(head==nullptr||*head==nullptr)return;
	ListNode* prenode = nullptr;
	ListNode* node = *head;
	while(node!=nullptr)
	{
		ListNode* next = node->next;
		bool needdelete = false;
		if(next!=nullptr&&next->value==node->value)needdelete = true;
		if(!needdelete)
		{
			prenode = node;
			node = node->next;
		}
		else
		{
			int value = node->value;
			ListNode* tobedelete = node;
			while(tobedelete!=nullptr&&tobedelete->value==value)
			{
				next = tobedelete->next;
				delete tobedelete;
				tobedelete = nullptr;
				tobedelete = next;
			}
			if(node==nullptr)
			{
				*head = next;
			}
			else
			{
				prenode->next = next;
			}
			node = next;
		}
	}
}
