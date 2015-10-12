#include <cstdlib>
#include <cstddef>
#include <cassert>
bool g_InPutInvalid = false;//检查输入是否正确
bool CheckInPutInvalid(int* number,int length)
{
	if(number==nullptr||length<=0)return false;
	return true;
}
void Swap(int* x,int * y)
{
	int temp = *x;
	*x=*y;
	*y=temp;
}
int Partition(int data[],int length,int start,int end)
{
	assert(data==nullptr||length<=0||start<0||end>=length);
	int index = rand() % (end-start+1) + start;//start-end
	Swap(&data[index],&data[end]);
	int small = start-1;
	for(index = start;index<end;index++)
	{
		if(data[index]<data[end])
		{
			++small;
			if(small!=index)
			{
				Swap(&data[index],&data[small]);
			}
		}
	}
	++small;
	Swap(&data[small],&data[end]);
	return small;
}
void GetLeastNumbers(int* input,int n,int* output,int k)
{
	if(input==nullptr||output==nullptr||n<=0||k<=0||k>n)return;
	int start = 0;
	int end = n-1;
	int index = Partition(input,n,start,end);
	while(index!=k-1)
	{
		if(index>k-1)
		{
			end = index-1;
			index = Partition(input,n,start,end);
		}
		else
		{
			start = index+1;
			index = Partition(input,n,start,end);
		}
	}
	for(int i =0;i<k;i++)
	{
		output[i] = input[i];
	}
}
