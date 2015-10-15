#include <cstdio>
void PrintContinuousSequence(int small,int big);
bool FindNumberWithSum(int* data,int length,int sum,int* num1,int* num2)
{
	bool found = false;
	if(data==nullptr||length<=0||num1==nullptr||num2==nullptr)return false;
	
	int ahead = length-1;
	int behind = 0;
	while(behind<ahead)
	{
		long long cursum = data[behind]+data[ahead];
		if(cursum<sum)
		{
			behind++;
		}
		else if(cursum>sum)
		{
			ahead--;
		}
		else if(cursum==sum)
		{
			*num1 = data[behind];
			*num2 = data[ahead];
			found = true;
			break;
		}
	}
	return found;
}
void FindContinuousSequence(int sum)
{
	if(sum<3)return;
	int small = 1;
	int big = 2;
	int middle = (sum+1)/2;
	int cursum = 3;
	while(small<middle)
	{
		if(cursum==3)
		{
			PrintContinuousSequence(small,big);
		}
		while(cursum>sum&&small<middle)
		{
			cursum -= small;
			small++;
			if(cursum==sum)
			{
				PrintContinuousSequence(small,big);
			}
		}
		big++;
		cursum+=big;
	}
}
void PrintContinuousSequence(int small,int big)
{
	for(int i=small;i<=big;i++)
	{
		printf("%d\t",i);
	}
	printf("\n");
}
