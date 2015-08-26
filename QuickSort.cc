#include <iostream>
#include <exception>
using namespace std;
int RandomInRange(int start,int end)
{
	return (start+end)/2;
}
void Swap(int* a,int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int Partition(int data[],int length,int start,int end)
{	
	if(data==NULL||length<=0||start<0||end>=length)
	{
		throw exception();
	}
	int index = RandomInRange(start,end);
	Swap(&data[index],&data[end]);
	int small = start-1;
	for(index = start;index<end;index++)
	{
		if(data[index]<data[end])
		{
			++small;
			if(index!=small)
			{
				Swap(&data[small],&data[index]);
			}
		}
	}
	++small;
	Swap(&data[small],&data[end]);
	for(int i=0;i<10;i++)
	{
		cout<<data[i]<<" ";
	} 
	cout<<endl;
	return small;
}
void QuickSort(int data[],int length,int start,int end)
{
	
	if(start==end)
	{
		return;
	}
	int index = Partition(data,length,start,end);
	if(index>start)
	{
		QuickSort(data,length,start,index-1);
	}
	if(index<end)
	{
		QuickSort(data,length,index+1,end);
	}
}
int main()
{
	int* data = new int[10];
	for(int i=0;i<10;i++)
	{
		data[i] = 9-i;
	}
				for(int i=0;i<10;i++)
	{
		cout<<data[i]<<" ";
	} 
	cout<<endl;
	QuickSort(data,10,0,9);
				for(int i=0;i<10;i++)
	{
		cout<<data[i]<<" ";
	} 
	cout<<endl;
	return 0;
}
