#include <cstddef>
struct ComplexListNode{
	int value;
	ComplexListNode* pNext;
	ComplexListNode* pSibling;
	};
void CloneNodes(ComplexListNode* pHead)
{
	if(pHead==nullptr) return;
	ComplexListNode* pNode = pHead;
	while(pNode!=nullptr)
	{
		ComplexListNode* pTemp = new ComplexListNode();
		pTemp->value = pNode->value;
		pTemp->pSibling = nullptr;
		pTemp->pNext = pNode->pNext;
		
		pNode->pNext = pTemp;
		pNode = pNode->pNext;
	}
}
void ConnectSiblingNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	while(pNode!=nullptr)
	{
		if(pNode->pSibling!=nullptr)
		{
			pNode->pNext->pSibling = pNode->pSibling->pNext;
		}
		pNode = pNode->pNext->pNext;
	}
}
ComplexListNode* ReconnectNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	ComplexListNode* pCloneHead = nullptr;
	ComplexListNode* pCloneNode = nullptr;
	if(pNode!=nullptr)
	{
		pCloneNode = pCloneHead = pNode->pNext;
		pNode->pNext = pCloneHead->pNext;
		pNode = pCloneHead->pNext;
	}
	while(pNode!=nullptr)
	{
		pCloneNode->pNext = pNode->pNext;
		pCloneNode = pCloneNode->pNext;
		pNode->pNext = pCloneNode->pNext;
		pNode = pNode->pNext;
	}
	return pCloneHead;
}
ComplexListNode* Clone(ComplexListNode* pHead)
{
	CloneNodes(pHead);
	ConnectSiblingNodes(pHead);
	return ReconnectNodes(pHead);
}
