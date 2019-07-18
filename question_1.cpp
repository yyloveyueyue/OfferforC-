/*
赋值运算符函数：
题目：提供一个类型CMyString的声明，为该类型添加赋值运算符函数
注意点：
1.将返回值的类型声明为该类型的引用，在函数结束前返回实例自身的引用；
2.把传入的参数类型声明为常亮引用
3.释放实例自身已有的内存
4.判断传入的参数和当前的实例是不是同一个。
 */

#include <cstring>
#include <iostream>
// #include<string>
using namespace std;

class CMyString
{
public:
    CMyString(const char* pData = nullptr);
    CMyString(const CMyString &str);
    ~CMyString(void);
    CMyString& operator=(const CMyString &str);	//重载 '=
    void getchar()
    {
        cout << this->m_pData << endl;
    }

private:
    char *m_pData;
};

//经典解法，适用于初级程序员
CMyString::CMyString(const char* pData)
{//构造函数1
	if (nullptr == pData)
	{//未传递值，给默认值0
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		m_pData = new char[strlen(pData) + 1];
		strcpy(m_pData,pData);
	}
}


CMyString::~CMyString()
{
    if (m_pData)
    {
        delete[] m_pData;
        m_pData = nullptr;
    }
}

CMyString::CMyString(const CMyString &str)
{
    cout << "这是拷贝构造函数！" << endl;
    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);
}

CMyString &CMyString::operator=(const CMyString &str)  //需要注意，必须在类声明中添加重载的声明，不然编译会报错
{
    if (this != &str)
    {
        delete[] m_pData;
        m_pData = nullptr;

        m_pData = new char[strlen(str.m_pData) + 1];
        strcpy(m_pData, str.m_pData);
    }

    return *this;
}


void test01(){
    
    CMyString s1("abc");
    // CMyString s2 = s1;
    CMyString s3 = s1;
    s3.getchar();
}
int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}