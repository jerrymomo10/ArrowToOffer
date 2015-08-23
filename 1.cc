#include <cstdio>//C++对C库的重写 C中的方法调用 C的头文件才有.h
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
		
class CMyString
{
public:
		CMyString(char* pData = NULL);
		CMyString(const CMyString& str);
		~CMyString(void);
		void print();
		CMyString& operator = (const CMyString& str);
private:
		char* m_pData;
};
CMyString::CMyString(char* pData)
{
		if(pData==NULL)
		{
				m_pData = new char[1];
				m_pData[0] = '\0';
		}
		else
		{
				m_pData = new char[strlen(pData)+1];
				strcpy(m_pData,pData);
		}
}
CMyString::CMyString(const CMyString& str)
{
		m_pData = new char[strlen(str.m_pData)+1];
		strcpy(m_pData,str.m_pData);
}
CMyString::~CMyString(void)
{
		delete []m_pData;
}
CMyString& CMyString::operator =(const CMyString& str)
{
		if(&str==this)return *this;
		CMyString Strtemp(str);
		char* temp = Strtemp.m_pData;
		Strtemp.m_pData = this->m_pData;
		this->m_pData = temp;
		return *this;
}
void CMyString::print()
{
		printf("%s\n",m_pData);
}

void test1()
{
		char* text= "Hello World!";
		CMyString str1(text);
		CMyString str2;
		CMyString str3;
		str3 = str2 = str1;
		str1.print();
		str2.print();
		str3.print();
}
int main()
{
		test1();
}
