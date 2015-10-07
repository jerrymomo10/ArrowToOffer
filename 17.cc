#include <iostream>

struct ListNode{
	int value;
	ListNode* next;
	};
ListNode* Merge(ListNode* pHead1,ListNode* pHead2)
{
	if(pHead1==NULL)return pHead2;
	if(pHead2==NULL)return pHead1;
	ListNode* pMerged = NULL;
	if(pHead1->value < pHead2->value)
	{
		pMerged = pHead1;
		pHead1->next = Merge(pHead1->next,pHead2);
		}
	else
	{
		pMerged = pHead2;
		pHead1->next = Merge(pHead2->next,pHead1);		
		}
	return pMerged;
	}
