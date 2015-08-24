#include <iostream>
using namespace std;
class singleton1
{
public:
	static singleton1* GetInstance()
	{
		if(m_Instance==NULL)
		{
			m_Instance = new singleton1();
		}
		return m_Instance;
	}
	static void DestroyInstance()
	{
		if(m_Instance!=NULL)
		{
			delete m_Instance;
			m_Instance = NULL;
		}
	}
	int GetText()
	{
		return m_Test;
	}
private:
	singleton1(){m_Test=10;}//仅仅在类内可以调用
	static singleton1* m_Instance;//全局仅有一个指针 staic类型的
	int m_Test;//just a example int
};
singleton1* singleton1::m_Instance = NULL;//静态变量的初始化必须在类以外

class singleton2
{
public:
	static singleton2* GetInstance()
	{
		if(m_Instance==NULL)
		{
			//lock
			//if(m_Instanck==NULL)
			m_Instance = new singleton2();
			//unlock
		}
		return m_Instance;
	}
	static void DestroyInstance()
	{
		if(m_Instance!=NULL)
		{
			delete m_Instance;
			m_Instance = NULL;
		}
	}
	int GetText()
	{
		return m_Test;
	}
private:
	singleton2(){m_Test=10;}//仅仅在类内可以调用
	static singleton2* m_Instance;//全局仅有一个指针 staic类型的
	int m_Test;//just a example int
};
singleton2* singleton2::m_Instance = NULL;//静态变量的初始化必须在类以外

//静态函数 在Main开始之前创建实例
class Singleton3
{
public:
     static Singleton3 *GetInstance()
     {
         static Singleton3 m_Instance;
         return &m_Instance;
     } 
     int GetTest()
     {
         return m_Test++;
     }
 
 private:
     Singleton3(){ m_Test = 10; };
     int m_Test;
 };
int GetSize(int data[])
{
	return sizeof(data);
}
int main(int argc,char* argv[])
{
	singleton1* singletonobj = singleton1::GetInstance();
	cout<<singletonobj->GetText()<<endl;
	singleton1::DestroyInstance();
	singleton1* singletonobj2 = singleton1::GetInstance();
	cout<<singletonobj2->GetText()<<endl;
	return 0;
}
