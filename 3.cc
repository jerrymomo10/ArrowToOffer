#include <iostream>
using namespace std;
bool Find(int* matrix,int rows,int columns,int number);
int main(int argc,char* argv[])
{
	int* mat = new int[100];
	for(int i=0;i<100;i++)
	{
		mat[i]=i;
	}
	bool f = Find(mat,10,10,233);
	f==true? cout<<"find the number"<<endl:cout<<"not find it"<<endl;
	return 0;
}
bool Find(int* matrix,int rows,int columns,int number)
{
	bool find = false;
	if(matrix!=NULL&&columns>0&&rows>0)
	{
		int r = 0;
		int c = columns-1;
		while(r<rows&&c>=0)
		{
			if(matrix[r*columns+c]==number)
			{
				find = true;
				break;
			}
			else if(matrix[r*columns+c]>number)
			{
				c--;
			}
			else
			{
				r++;
			}
		}
	}
	return find;
}
