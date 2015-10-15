#include <cstring>
#include <cstdlib>
void Reverse(char* begin,char* end)
{
	if(begin==nullptr||end==nullptr)return;
	while(begin<end)
	{
		char temp = *begin;
		*begin = *end;
		*end = temp;
		begin++;
		end--;
	}
}
char* ReverseSentence(char* data)
{
	if(data==nullptr)return nullptr;
	char* begin = data;
	char* end = data;
	while(*end!='\0')
	{
		end++;
	}
	end--;
	Reverse(begin,end);
	begin = end = data;
	while(*begin!='\0')
	{
		if(*begin==' ')
		{
			begin++;
			end++;
		}
		else if(*end==' '||*end=='\0')
		{
			Reverse(begin,end);
			end++;
			begin = end;
		}
		else
		{
			end++;
		}
	}
	return data;
}
char* LeftRotateString(char* str,int n)
{
	if(str==nullptr)return str;
	int length = static_cast<int>(strlen(str));//类型转换
	if(length>0&&n>0&&n<length)
	{
		char* pFirstStart = str;
		char* pFirstEnd = str+n-1;
		char* pSecondStart = str+n;
		char* pSecondEnd = str+length-1;
		
		Reverse(pFirstStart,pFirstEnd);
		Reverse(pSecondStart,pSecondEnd);
		Reverse(pFirstStart,pSecondEnd);
	}
	return str;
	
}
