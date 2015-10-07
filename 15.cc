#include <iostream>
struct ListNode{
	int value;
	ListNode* next;
	};
ListNode* FindKthToTail(ListNode* head,int k)
{
	if(head==NULL||k<1)return NULL;
	ListNode* pAhead = head, *pBehind=head;
	for(int i=0;i<k;k++)
	{
		if(pAhead==NULL)return NULL;
		pAhead = pAhead->next;
	}
	while(pAhead!=NULL)
	{
		pAhead = pAhead->next;
		pBehind = pBehind->next;
		}	
	return pBehind;
}
