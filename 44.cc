#include <cstdlib>
int compare(const void* x,const void* y);
bool IsContinuous(int* number,int length)
{
	if(number==nullptr||length<=0)return false;
	qsort(number,length,sizeof(int),compare);
	
	int numberOfZeros = 0;
	int numberOfGap = 0;
	
	for(int i=0;i<length;i++)
	{
		if(number[i]==0)numberOfZeros++;
	}
	int small = numberOfZeros;
	int big = small+1;
	while(big<length)
	{
		if(number[small]==number[big])return false;
		numberOfGap += number[big]-number[small];
		small = big;
		big++;
	}
	return numberOfZeros>=numberOfGap?true:false;
}
int compare(const void* x,const void* y)
{
	return *(int*)x-*(int*)y;
}
