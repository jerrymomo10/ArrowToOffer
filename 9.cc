#include <iostream>
using namespace std;
long long Fabonacci(unsigned int n)
{
	if(n<=0)return 0;
	if(n==1)return 1;
	return Fabonacci(n-1)+Fabonacci(n-2);
}
long long Fabonacci2(unsigned n)
{
	if(n<=0)return 0;
	if(n==1)return 1;
	long long first=0;
	long long second=1;
	long long temp;
	for(unsigned int i=2;i<=n;i++)
	{
		temp = first+second;
		first = second;
		second = temp;
	}
	return second;
}
int main()
{
	cout<<Fabonacci2(500);
	return 0;
}
