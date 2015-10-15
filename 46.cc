#include <cstdio>
class Temp{
	private:
	static unsigned int N;
	static unsigned int sum;
	public:
	Temp()
	{
		N++;
		sum+=N;
	} 
	static void Reset(){N=0;sum=0;}
	static int GetSum(){return sum;}
	};
unsigned int Temp::N = 0;
unsigned int Temp::sum = 0;
unsigned int Sum_solution1(unsigned int n)
{
	Temp::Reset();
	Temp *a = new Temp[n];
	delete []a;
	return Temp::GetSum();
}
class A;
A* Array[2];
class A{
	public:
		virtual unsigned int Sum(unsigned int n)
		{
			return 0;
		}
	};
class B:public A{
	public:
		virtual unsigned int Sum(unsigned int n)
		{
			return Array[!!n]->Sum(n-1)+n;
		}
};
int Sum_solution2(unsigned int n)
{
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;
	int value = Array[1]->Sum(n);
	return value;
}
typedef unsigned int (*fun)(unsigned int);
unsigned int Solution3_terminator(unsigned int n)
{
	return 0;
}
unsigned int Sum_solution3(unsigned int n)
{
	static fun f[2] = {Solution3_terminator,Sum_solution3};
	return n+f[!!n](n-1);
}
template<unsigned int n> struct Sum_solution4{
	enum Value{N = Sum_solution4<n-1>::N+n};
	};
template<> struct Sum_solution4<1>
{
	enum Value{N=1};
};
int main()
{
	printf("%d",Sum_solution2(100));
}
