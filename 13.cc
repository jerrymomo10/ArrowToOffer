#include <iostream>
struct ListNode{
	int value;
	ListNode* next;
	};
void DeleteNode(ListNode** plistHead,ListNode* pToBeDeleted)
{
	if(plistHead==NULL||*plistHead==NULL||pToBeDeleted==NULL)return;
	if(pToBeDeleted!=NULL)
	{
		ListNode* temp = pToBeDeleted->next;
		pToBeDeleted->value = temp->value;
		pToBeDeleted->next = temp->next;
		delete temp;
		temp = NULL;
	}
	else if(*plistHead==pToBeDeleted)
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		*plistHead = NULL;
	}
	else
	{
		ListNode* temp = *plistHead;
		while(temp->next!=pToBeDeleted)
		{
			temp = temp->next;
			}
		temp->next = NULL;
		delete pToBeDeleted;
		pToBeDeleted = NULL;
		}
	}

