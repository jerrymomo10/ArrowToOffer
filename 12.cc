#include <stdio.h>//c
#include <string.h> //c
void PrintNumber(char* number)
{
	bool isBeginning0 = true;
	int nLength = strlen(number);
	for(int i=0;i<nLength;i++)
	{
		if(isBeginning0==true&&number[i]!='0')
		{
			isBeginning0 = false;
			}
		if(isBeginning0==false)
		{
			printf("%c",number[i]);
		}
		}
	printf("%c",'\t');
	}
void Print1ToMaxOfNDigits(int n);
void Print1ToMaxOfNDigits2(int n);
int main()
{
	Print1ToMaxOfNDigits2(4);
	return 0;
}
bool Increment(char* number);//返回是否OVERFLOW
void Print1ToMaxOfNDigits(int n)
{
	if(n<=0)return;
	char *numbers = new char[n+1];
	memset(numbers,'0',n);
	numbers[n] = '\0';
	while(!Increment(numbers))
	{
		PrintNumber(numbers);
	}
	delete []numbers;
	
}
bool Increment(char* number)
{
	bool isOverflow = false;
	int nTakeOver = 0;
	int nlength = strlen(number);
	for(int i = nlength-1;i>=0;i--)
	{
		int nSum = number[i]-'0'+nTakeOver;
		if(i==nlength-1) nSum++;
		if(nSum>=10)
		{
			if(i==0)isOverflow = true;
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0'+nSum;
				}
		}
		else
		{
			number[i] = nSum+'0';
			break;
		}
	}
	return isOverflow;
	
}
void Print1ToMaxOfDigitsRecursively(char* numbers,int length,int index)
{
	if(index == length)
	{
		PrintNumber(numbers);
		return;
	}
	else
	{
		for(int i =0;i<10;i++)
		{
			numbers[index+1]='0'+i;
			Print1ToMaxOfDigitsRecursively(numbers,length,index+1);
		}
	}
}
void Print1ToMaxOfNDigits2(int n)
{
	if(n<=0)return;
	char* number = new char[n+1];
	memset(number,'0',n);
	number[n] = '\0';
	Print1ToMaxOfDigitsRecursively(number,strlen(number),0);
	delete number;
}
