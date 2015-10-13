#include <cstdlib>
#include <cstring>
#include <cstdio>
const int g_MaxNumberLength = 10;

char* g_strCombine1 = new char[g_MaxNumberLength*2+1];
char* g_strCombine2 = new char[g_MaxNumberLength*2+1];
int compare(const void* strNumbers1,const void* strNumbers2);
void PrintMinNumber(int* numbers,int length)
{
	if(numbers==nullptr||length<=0)return;
	char** strNumbers = new char*[length];
	for(int i=0;i<length;i++)
	{
		strNumbers[i] = new char[g_MaxNumberLength+1];
		sprintf(strNumbers[i],"%d",numbers[i]);
	}
	qsort(strNumbers,length,sizeof(char*),compare);
	for(int i = 0;i<length;i++)
	{
		printf("%s",strNumbers[i]);
	}
	printf("\n");
	for(int i =0;i<length;i++)
	{
		delete[] strNumbers[i];
	}
	delete[] strNumbers;
}
int compare(const void* strNumbers1,const void* strNumbers2)
{
	strcpy(g_strCombine1,*(const char**)strNumbers1);
	strcat(g_strCombine1,*(const char**)strNumbers2);
	
	strcpy(g_strCombine2,*(const char**)strNumbers2);
	strcat(g_strCombine2,*(const char**)strNumbers1);
	
	return strcmp(g_strCombine1,g_strCombine2);
}
