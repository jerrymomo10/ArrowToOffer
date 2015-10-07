#include <iostream>
typedef struct ListNode{
	int value;
	ListNode* next;
	} List;
List* ReverseList(List* head)
{
	List* pReverseHead = NULL;
	List* pNode = head;
	List* pPre = NULL;
	while(pNode!=NULL)
	{
		List* pNext = pNode->next;
		if(pNext==NULL)pReverseHead = pNode;
		pNode->next = pPre;
		
		pPre = pNode;
		pNode = pNext;
		}
	return pReverseHead;
	}
List* ReverseListRecursively(List* head)
{
	if(head==NULL||head->next==NULL)return head;
	else
	{
		List* NewHead = ReverseListRecursively(head->next);//Tail
		head->next->next = head;
		head->next = NULL;
		return NewHead;
		}

}

