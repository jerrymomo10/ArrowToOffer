int GetFirstK(int* data,int length,int k,int start,int end)
{
	if(start>end)return -1;
	int middleIndex = (start+end)/2;
	int middledata = data[middleIndex];
	if(middledata>k)
	{
		end = middleIndex-1;
	}
	if(middledata<k)
	{
		start = middleIndex+1;
	}
	if(middledata==k)
	{
		if((middleIndex>0&&data[middleIndex-1]!=k)||middleIndex==0)
		{
			return middleIndex;
		}
		else
			end = middleIndex-1;
	}
	return middleIndex;
}
int GetLastK(int* data,int length,int k,int start,int end)
{
	if(start>end)return -1;
	int middleIndex = (start+end)/2;
	int middledata = data[middleIndex];
	if(middledata>k)
	{
		end = middleIndex-1;
	}
	if(middledata<k)
	{
		start = middleIndex+1;
	}
	if(middledata==k)
	{
		if((middleIndex<length-1&&data[middleIndex+1]!=k)||middleIndex==length-1)
		{
			return middleIndex;
		}
		else
			start = middleIndex+1;
	}
	return middleIndex;
}
int GetNumberOfK(int* data,int length,int K)
{
	if(data==nullptr||length<=0)return 0;
	int number = 0;
	int first = GetFirstK(data,length,K,0,length-1);
	int last = GetLastK(data,length,K,0,length-1);
	if(first>-1&&last>-1)
	{
		number = last-first+1;
	}
	return number;
}
