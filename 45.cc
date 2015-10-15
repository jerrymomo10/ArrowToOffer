#include <list>
using namespace std;
int LastRemaining(unsigned int n,unsigned int m)
{
	if(n<1||m<1)return -1;
	unsigned int i = 0;
	list<int> numbers;
	for(i = 0;i<n;i++)
	{
		numbers.push_back(i);
	}
	list<int>::iterator current = numbers.begin();
	while(numbers.size()>1)
	{
		for(unsigned int i =1;i<m;i++)
		{
			current++;
			if(current==numbers.end())
			{
				current = numbers.begin();
			}
		}
		auto next = ++current;
		if(next==numbers.end())next = numbers.begin();
		--current;
		numbers.erase(next);
	}
	return *current;
}
