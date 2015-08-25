#include <stack>
using namespace std;

template <typename T> 
class CQueue
{
public:
	CQueue(){};
	~CQueue(){};
	void appendTail(const T& node);
	T deleteHead();
private:
	stack<T> stackin;
	stack<T> stackout;
};
template <typename T>
void CQueue<T>::appendTail(const T& node)
{
	stackin.push(node);
}
template<typename T>
T CQueue<T>::deleteHead()
{
	if(stackout.empty())
	{
		T data;
		while(!stackin.empty())
		{
			data = stackin.top();
			stackin.pop();
			stackout.push(data);
		}
	}
	if(stackout.empty())
	{
		throw exception();
	}
	T head = stackout.top();
	stackout.pop();
	return head;
}
int main()
{
	CQueue<int> cq;
	cq.appendTail(1);
	cq.appendTail(2);
	cq.appendTail(3);
	cq.appendTail(4);
	return 0;
}
