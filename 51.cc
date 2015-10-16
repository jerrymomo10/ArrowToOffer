bool duplicate(int* number,int length,int* dupliaction)
{
	if(number==nullptr||length<=0)return false;
	for(int i = 0;i<length;i++)
	{
		if(number[i]<0||number[i]>length-1)
		return false;
	}
	for(int i=0;i<length;i++)
	{
		while(number[i]!=i)
		{
			if(number[i]==number[number[i]])
			{
				*dupliaction = number[i];
				return true;
			}
			int temp = number[i];
			number[i] = number[temp];
			number[temp] = temp;
		}
	}
	return false;
}
