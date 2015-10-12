#include <cstdlib>
#include <cstddef>
#include <cassert>
bool g_InPutInvalid = false;//检查输入是否正确
bool CheckInPutInvalid(int* number,int length)
{
	if(number==nullptr||length<=0)return false;
	return true;
}
bool CheckMoreThanHalf(int* numbers,int length,int data)
{
	int times = 0;
	for(int i =0;i<length-1;i++)
	{
		if(numbers[i]==data)times++;
	}
	bool isMoreThanHalf = true;
	if(times*2<=length)
	{
		g_InPutInvalid = true;
		isMoreThanHalf = false;
	}
	return isMoreThanHalf;
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
int MoreThanHalfNum(int* numbers,int length)
{
	if(CheckInPutInvalid(numbers,length))return 0;
	int middle = length>>2;
	int start = 0;
	int end = length-1;
	int index = Partition(numbers,length,start,end);
	while(index!=middle)
	{
		if(index>middle)
		{
			end = index-1;
			index = Partition(numbers,length,start,end);
		}
		else
		{
			start = index+1;
			index = Partition(numbers,length,start,end);
		}
	}
	int result = numbers[middle];
	if(!CheckMoreThanHalf(numbers,length,result))
	return 0;
	else
	{
		return result;
	}
}
int MoreThanHalfNum2(int* numbers,int length)
{
	if(CheckInPutInvalid(numbers,length))return 0;
	int result = numbers[0];
	int times = 1;
	for(int i =1;i<length;i++)
	{
		if(times==0)
		{
			result = numbers[i];
			times++;
		}
		else if(result==numbers[i])
		{
			times++;
		}
		else
		{
			times--;
		}
	}
	if(!CheckMoreThanHalf(numbers,length,result))
	return 0;
	else
	{
		return result;
	}
}
