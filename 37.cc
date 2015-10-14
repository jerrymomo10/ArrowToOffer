struct ListNode{
	int value;
	ListNode* next;
};
unsigned int GetListLength(ListNode* pHead)
{
	unsigned int count = 0;
	ListNode* t = pHead;
	while(t!=nullptr)
	{
		count++;
		t = t->next;
	}
	return count;
}
ListNode* GetFirstCommonNode(ListNode* pHead1,ListNode* pHead2)
{
	unsigned int length1 = GetListLength(pHead1);
	unsigned int length2 = GetListLength(pHead2);
	int LengthDif = length1-length2;
	ListNode* pLong = pHead1;
	ListNode* pShort = pHead2;
	if(LengthDif<0)
	{
		pLong = pHead2;
		pShort = pHead1;
	}
	for(int i=0;i<LengthDif;i++)
	{
		pLong = pLong->next;
	}
	while(pLong!=nullptr&&pShort!=nullptr&&(pLong!=pShort))
	{
		pLong = pLong->next;
		pShort = pShort->next;
	}
	ListNode* pFistCommonListNode = pLong;
	return pFistCommonListNode;
}
