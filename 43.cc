#include <cmath>
#include <cstdio>
int g_maxValue = 6;
void Probobility(int number,int* Prob);
void Probobility(int original,int current,int sum,int* Prob);
void PrintProbility(int n)
{
	if(n < 1)return;
	int maxSum = n*g_maxValue;
	int* Probobilities = new int[maxSum-n+1];
	for(int i = n;i<=maxSum;i++)
	{
		Probobilities[i-n]=0;
	}
	Probobility(n,Probobilities);
	int total = pow((double)g_maxValue,n);
	for(int i = n;i<=maxSum;i++)
	{
		double ratio = (double)Probobilities[i]/total;
		printf("%d: %e\n",i,ratio);
	}
	delete[] Probobilities;
}
void Probobility(int n,int* Prob)
{
	for(int i=1;i<=g_maxValue;i++)
	{
		Probobility(n,n,i,Prob);
	}
}
void Probobility(int original,int current,int sum,int* Prob)
{
	if(current==1)
	{
		Prob[sum-original]++;
	}
	else
	{
		for(int i=1;i<=g_maxValue;i++)
		{
			Probobility(original,current-1,i+sum,Prob);
		}
	}
}
void PrintProbility2(int number);
int main()
{
	PrintProbility2(3);
	PrintProbility(3);
}
void PrintProbility2(int number)
{
	if(number<1)return;
	int* Prob[2];
	Prob[0] = new int[g_maxValue*number+1];
	Prob[1] = new int[g_maxValue*number+1];
	for(int i = 0;i<g_maxValue*number+1;i++)
	{
		Prob[0][i] = 0;
		Prob[1][i] = 0;
	}
	int flag = 0;
	for(int i =1;i<=g_maxValue;i++)
	{
		Prob[flag][i] = 1;
		
	}
	for(int k=2;k<=number;k++)
	{
		for(int i=0;i<k;i++)
		{
			Prob[1-flag][i] = 0;
		}
		for(int i=k;i<=g_maxValue*k;i++)
		{
			Prob[1-flag][i]=0;
			for(int j=1;j<=i&&j<=g_maxValue;j++)
			{
				Prob[1-flag][i]+=Prob[flag][i-j];
			}
			
		}
		flag=1-flag;
	}
	double total = pow((double)g_maxValue,number);
	for(int i = number;i<=g_maxValue*number;i++)
	{
		double ratio = (double)Prob[flag][i]/total;
		printf("%d: %e\n",i,ratio);
	}
	delete[] Prob[0];
	delete[] Prob[1];
}
