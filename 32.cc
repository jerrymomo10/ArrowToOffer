#include <cstdio>
#include <cstdlib>
#include <cstring>
int NumberOf1(char* str);
int NumberOf1Between1AndN(int n)
{
	if(n<=0)return 0;
	char strN[50];
	sprintf(strN,"%d",n);//格式化 整数转换成十进位
	return NumberOf1(strN);
}
int PowerBase10(int n)
{
	int result = 1;
	for(int i=0;i<n;i++)
	{
		result*=10;
	}
	return result;
}
int NumberOf1(char* str)
{
	if(str==nullptr||*str<'0'||*str>'9'||*str=='\0')return 0;
	int first = *str-'0';
	unsigned int length = static_cast<unsigned int>(strlen(str));
	
	if(length==1&&first==0)return 0;
	if(length==1&&first>0)return first;
	
	int numFirstDigit = 0;
	if(first>1)
	{
		numFirstDigit = PowerBase10(length-1);
	}
	else if(first==1)
	{
		numFirstDigit = atoi(str+1)+1;
	}
	int numOtherDigits = first*(length-1)*PowerBase10(length-2);
	int numRecursive = NumberOf1(str+1);
	return numFirstDigit+numOtherDigits+numRecursive;
}
