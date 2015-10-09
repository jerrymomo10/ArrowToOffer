#include <cstddef>
#include <stack>
using namespace std;
template<class T>
class StackWithMin{
private:
	stack<T> data_stack;
	stack<T> min_stack;
public:
	void push(const T& value);
	void pop();
	T min()const;
	};
template<class T>
void StackWithMin<T>::push(const T& value)
{
	data_stack.push(value);
	if(min_stack.size()==0||min_stack.top>value)
	{
		min_stack.push(value);
	}
	else
	{
		min_stack.push(min_stack.top());
	}
}
template<class T>
void StackWithMin<T>::pop()
{
	assert(data_stack.size()>0&&min_stack.size()>0);
	data_stack.pop();
	min_stack.pop();
	}
template<class T>
T StackWithMin<T>::min()const
{
	assert(data_stack.size()>0&&min_stack.size()>0);
	return min_stack.top();
	}
