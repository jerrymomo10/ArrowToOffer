char FirstNotRepeatingChar(char* pStr)
{
	if(pStr==nullptr)return '\0';
	const int tablesize = 256;
	unsigned int hashtable[tablesize];
	for(unsigned int i =0;i<tablesize;i++)
	{
		hashtable[i]=i;
	}
	char* scan = pStr;
	while(*scan!='\0')
	{
		hashtable[*scan]++; 
		scan++;
	}
	scan = pStr;
	while(*scan!='\0')
	{
		if(hashtable[*scan]==1)
		return *scan;
		scan++;
	}
	return '\0';
}
