#include <exception>
#include <iostream>
using namespace std;
int MinInOrder(int* numbers,int index1,int index2);
int Min(int* numbers,int length)
{
	if(numbers==NULL||length<=0)
	{
		throw new exception();
	}
	int index1 = 0;
	int index2 = length-1;
	int indexMid = index1;
	while(numbers[index1]>=numbers[index2])
	{
		if((index2-index1)==1)
		{
			indexMid = index2;
			break;
		}
		indexMid = (index1+index2)/2;
		if(numbers[index1]==numbers[index2]&&numbers[index1]==numbers[indexMid])
		{
			return MinInOrder(numbers,index1,index2);
		}
		if(numbers[indexMid]>=numbers[index1])
		{
			index1 = indexMid;
		}
		else if(numbers[indexMid]<=numbers[index2])
		{
			index2 = indexMid;
		}
	}
	return numbers[indexMid];
}
int MinInOrder(int* numbers,int index1,int index2)
{
	int result = numbers[index1];
	for(int i=index1+1;i<=index2;i++)
	{
		if(numbers[i]<result)
		{
			result = numbers[i];
		}
	}
	return result;
}
int main()
{
	int* test = new int[10];
	for(int i=0;i<10;i++)
	{
		test[i]=(i+3)%10;
	}
	test[0]=4;
		for(int i=0;i<10;i++)
	{
		cout<<test[i]<<" ";
	}
	cout<<endl;
	test = NULL;
	cout<<Min(test,1)<<endl;
	return 0;
}
