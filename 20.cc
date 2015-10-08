#include <cstdio>
void PrintMatrixCircle(int** number,int rows,int columns,int start);
void PrintMatrixClockWisely(int** number,int rows,int columns)
{
	if(number==nullptr||rows <= 0|| columns <= 0)return ;
	int start = 0;
	while(start*2 < rows&&start*2 <columns)
	{
		PrintMatrixCircle(number,rows,columns,start);
		start++;
		}
	}
void PrintMatrixCircle(int** number,int rows,int columns,int start)
{
	int endx = rows-1-start;
	int endy = columns-1-start;
	
	//从左向右
	for(int i=start;i<=endy;i++)
	{
		printf("%d\t",number[start][i]);
	}
	if(start<endx)
	{
		for(int i=start+1;i<endx;i++)
		{
			printf("%d\t",number[i][endy]);
			}
	}
	if(start<endx&&start<endy)
	{
		for(int i=endy-1;i>=start;i--)
		{
			printf("%d\t",number[endy][i]);
			}
		}
	if(start<endy&&start<endx-1)
	{
		for(int i=endx-1;i>=start+1;i--)
		printf("%d\t",number[i][start]);
		}
}
