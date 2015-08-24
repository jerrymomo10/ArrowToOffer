#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
void replaceBlank(char str[],int length)
{
	if(str==NULL||length<=0)return;//指针为空或者空字符串
	int originalLength = 0;
	int numberOfLength = 0;
	while(str[originalLength]!='\0')
	{
		if(str[originalLength]==' ')
		{
			numberOfLength++;
		}
		originalLength++;
	}
	int newLength = originalLength+2*numberOfLength;
	if(newLength>length)return;
	int indexOfLength = originalLength;
	int indexOfNewlength = newLength;
	while(indexOfLength>=0)
	{
		if(str[indexOfLength]==' ')
		{
			str[indexOfNewlength--]='0';
			str[indexOfNewlength--]='2';
			str[indexOfNewlength--]='%';
		}
		else
		{
			str[indexOfNewlength--] = str[indexOfLength];
		}
		indexOfLength--;
	}
}
int main(int argc,char* argv[])
{
	char str[] = " I am  Jerry ";
	replaceBlank(str,30);
	printf("%s",str);
	return 0;
}
