//判断INT型变量的第几位是不是1
bool IsBit1(int number,unsigned int indexBit)
{
	number = number>>indexBit;
	return number&0x1;
}
unsigned int FindFirstBitIs1(int num)
{
	unsigned int indexBit = 0;
	while((num&0x1)!=0&&indexBit<sizeof(int)*8)
	{
		num = num>>1;
		++indexBit;
	}
	return indexBit;
}
void FindNumberAppearOnce(int* data,int length,int* num1,int* num2)
{
	if(data==nullptr||length<2)return;
	int resultExclusionOR = 0;
	for(int i =0;i<length;i++)
	{
		resultExclusionOR ^= data[i];
	}
	unsigned int indexOf1 = FindFirstBitIs1(resultExclusionOR);
	*num1 = *num2 = 0;
	for(int i=0;i<length;i++)
	{
		if(IsBit1(data[i],indexOf1))
		{
			*num1 ^= data[i];
		}
		else
		{
			*num2 ^= data[i];
		}
	}
}

