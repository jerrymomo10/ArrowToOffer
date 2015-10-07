#include <iostream>
void ReOrderOddEven(int* pData,int length)
{
	if(pData==NULL||length==0)return;
	int* pBegin = pData;
	int* pEnd =pData+length-1;
	while(pBegin<pEnd)
	{
		while((pBegin<pEnd)&&(((*pBegin)&(0x1))==1))pBegin++;
		while((pBegin<pEnd)&&(((*pEnd)&(0x1))!=1))pEnd--;
		
		int temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd= temp;
	}
}
void ReOrder(int *pData,int length,bool (*func)(int))
{
		if(pData==NULL||length==0)return;
	int* pBegin = pData;
	int* pEnd =pData+length-1;
	while(pBegin<pEnd)
	{
		while((pBegin<pEnd)&&func(*pBegin))pBegin++;
		while((pBegin<pEnd)&&!func(*pEnd))pEnd--;
		
		int temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd= temp;
	}
}
bool isEven(int i)
{
	return (i&(0x1))==0;
}
void ReOrderOddEven2(int* pData,int length)
{
	ReOrder(pData,length,isEven);
}
