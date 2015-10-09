#include <cstddef>
#include <stack>
using namespace std;
bool IsPopOrder(const int* pPush,const int* pPop,int length)
{
	bool bPossible = true;
	if(pPush!=nullptr&&pPop!=nullptr&&length>0)
	{
		const int* pPopnext = pPop;
		const int* pPushnext = pPush;
		stack<int> data_stack;
		while(pPopnext-pPop<length)
		{
			//每一步判断一个POP数组里的一个数
			while(data_stack.empty()||data_stack.top()!=*pPopnext)
			{
				if(pPushnext-pPush==length)break;//当不可能时，会一直走到最后的，并且data_stack.top()!=*pPop
				data_stack.push(*pPushnext);
				pPushnext++;
			}
			if(data_stack.top()!=*pPopnext)break;
			data_stack.pop();
			pPopnext++;
		}
		if(data_stack.empty()&&pPopnext-pPop==length)bPossible = true;
	}
	return bPossible;
}
