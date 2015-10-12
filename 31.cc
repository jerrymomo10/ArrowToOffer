#include <climits>
bool g_InvalidInput = false;
int findGreastSumOfSubArray(int* numbers,int length)
{
	if(numbers==nullptr||length<=0)
	{
		g_InvalidInput = true;
		return 0;
	}
	g_InvalidInput = false;
	int nCurSum = 0;
	int nGreatestSum = INT_MIN;
	for(int i =0;i<length;i++)
	{
		if(nCurSum<0)
		{
			nCurSum = numbers[i];
		}
		else
		{
			nCurSum = numbers[i]+nCurSum;
			if(nGreatestSum<nCurSum)
			{
				nGreatestSum = nCurSum;
			}
		}
	}
	return nGreatestSum;
}
