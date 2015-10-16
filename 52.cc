#include <vector>
using namespace std;
void multiply(const vector<double>& array1,vector<double>& array2)
{
	int length1 = array1.size();
	int length2 = array2.size();
	if(length1==length2&&length1>1)
	{
		array2[0]=1;
		for(int i=1;i<length2-1;i++)
		{
			array2[i] = array2[i-1]*array1[i-1];
		}
		double temp = 1;
		for(int i = length1-2;i>=0;i--)
		{
			temp = temp*array1[i+1];
			array2[i] = temp*array2[i];
		}
	}
}
