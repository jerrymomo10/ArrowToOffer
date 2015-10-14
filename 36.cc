int InverseParisCore(int* data,int* copy,int start,int end);
int InVerseParis(int* data,int length)
{
	if(data==nullptr||length<=0)return 0;
	int* copy = new int[length];
	for(int i=0;i<length;i++)
	{
		copy[i] = data[i];
	}
	int count = InverseParisCore(data,copy,0,length);
	delete[] copy;
	return count;
}
int InverseParisCore(int* data,int* copy,int start,int end)
{
	if(start==end)
	{
		copy[start] = data[start];
		return 0;
	}
	int length = (end-start)/2;
	int left = InverseParisCore(copy,data,start,start+length);
	int right = InverseParisCore(copy,data,start+length+1,end);
	
	int i = start+length;
	int j = end;
	int indexcopy = end;
	int count = 0;
	while(i>=start&&j>=start+length+1)
	{
		if(data[i]>data[j])
		{
			copy[indexcopy--] = data[i--];
			count += j-length-start;
		}
		else
		{
			copy[indexcopy--] = data[j--];
		}
	}
	for(;i>=start;i--)
	{
		copy[indexcopy--] = data[i];
	}
	for(;j>=start+length+1;j--)
	{
		copy[indexcopy--] = data[j];
	}
	return left+right+count;
}
