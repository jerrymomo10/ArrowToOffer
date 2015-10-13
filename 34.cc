#include <iostream>
using namespace std;
int Min(int x,int y,int z);
int GetUglyNumber(int index)
{
	if(index<=0)return 0;
	int *pUglyNumbers = new int[index];
	pUglyNumbers[0] = 1;
	int nextUglyIndex = 1;
	int* pMultiply2 = pUglyNumbers;
	int* pMultiply3 = pUglyNumbers;
	int* pMultiply5 = pUglyNumbers;
	while(nextUglyIndex<index)
	{
		int min = Min((*pMultiply2)*2,(*pMultiply3)*3,(*pMultiply5)*5);
		pUglyNumbers[nextUglyIndex] = min;
		while((*pMultiply2)*2 <= pUglyNumbers[nextUglyIndex])
		{
			pMultiply2++;
		}
		while((*pMultiply3)*3 <= pUglyNumbers[nextUglyIndex])
		{
			pMultiply3++;
		}
		while((*pMultiply5)*5 <= pUglyNumbers[nextUglyIndex])
		{
			pMultiply5++;
		}
		nextUglyIndex++;
	}
	int ugly = pUglyNumbers[index-1];
	delete[] pUglyNumbers;
	return ugly;
}
int Min(int x,int y,int z)
{
	int min = x<y? x:y;
	min = min<z? min:z;
	return min;
}
int main()
{
	cout<<GetUglyNumber(0)<<endl;
	return 1;
}
