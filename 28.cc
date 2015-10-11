#include <cstddef>
#include <cstdio>
void Permutation(char* pStr,char* pBegin);
void Permutation(char* pStr)
{
	if(pStr==nullptr)return;
	Permutation(pStr,pStr);
}
void Permutation(char* pStr,char* pBegin)
{
	if(*pBegin=='\0')
	{
		printf("%s\n",pStr);
	}
	else
	{
		for(char* pCh = pBegin;*pCh!='\0';pCh++)
		{
			char temp = *pBegin;
			*pBegin = *pCh;
			*pCh = temp;
			Permutation(pStr,pBegin+1);
			
			temp = *pBegin;
			*pBegin = *pCh;
			*pCh = temp;
		}
	}
}
int main()
{
	char* x= new char[4];
	x[0]='a';
	x[1]='b';
	x[2]='c';
	x[3]='\0';
	Permutation(x);
	return 0;
}
