#include <stack>
#include <cstdio>
using namespace std;
struct ListNode
{
	int value;
	ListNode* next;
	ListNode(int x){value=x;}
};
void PrintListReversely_Iteratively(ListNode* head)
{
	stack<ListNode*> st;
	ListNode* temp = head;
	while(temp!=NULL)
	{
		st.push(temp);
		temp = temp->next;
	}
	while(!st.empty())
	{
		temp = st.top();
		printf("%d\n",temp->value);
		st.pop();
	}
}
void PrintListReversely_recursively(ListNode* head)
{
	if(head!=NULL)
	{
		if(head->next!=NULL)
		{
			PrintListReversely_recursively(head->next);
		}
		printf("%d\n",head->value);
	}
}
int main(int argc,char* argvs[])
{
	ListNode* list = new ListNode(1);
	list->next = new ListNode(2);
	list->next->next = new ListNode(3);
	PrintListReversely_recursively(list);
	return 0;
}
