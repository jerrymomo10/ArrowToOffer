#include <iostream>
using namespace std;
bool g_InvalidInput = false;
double PowerWithUnsignedExponent(double base,unsigned int exponent)
{
	double result = 1.0;
	for(unsigned i = 1;i<=exponent;i++)
	{
		result *= base;
		}
	return result;
	}
double PowerWithUnsignedExponent2(double base,unsigned int exponent)
{
	if(exponent==0)return 1;
	if(exponent==1)return base;
	double result = PowerWithUnsignedExponent2(base,exponent>>1);
	result *= result;
	if(((exponent)&(0x1))==1)result*=base;
	return result;
	}
bool equal(double num1,double num2)
{
	double left = 0.0000001;
	if((num1-num2)<left&&(num2-num1)<left) return true;
	else return false; 
	}
double Power(double base,int exponent)
{
	g_InvalidInput = false;
	if(equal(base,0.0)&&exponent<0)
	{
		g_InvalidInput = false;
		return 0.0;
		}
	unsigned int absExponent = exponent>0?exponent:-exponent;
	double result = PowerWithUnsignedExponent2(base,absExponent);
	if(exponent<0)
	return 1.0/result;
	else return result;
	}
int main()
{
	cout<<Power(8.0,8)<<endl;
}
