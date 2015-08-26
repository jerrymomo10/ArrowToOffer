#include <iostream>
using namespace std;
int NumberOf1(int n)
{
	int count = 0;
	while(n!=0)
	{
		if((n&0x80000000)!=0)
		{
			count++;
		}
		n=n<<1;
	}
	return count;
}
int NumberOf2(int n)
{
	int count = 0;
	int flag = 1;
	while(flag!=0)
	{
		if((n&flag)!=0)
		{
			count++;
		}
		flag=flag<<1;
	}
	return count;
}
int NumberOf3(int n)
{
	int count = 0;
	while(n)
	{
		++count;
		n = n&(n-1);
	}
	return count;
}
int main()
{
	cout<<NumberOf3(0xffffffff)<<endl;
}
