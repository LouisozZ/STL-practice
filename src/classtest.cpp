/**
 * 对构造函数以及函数指针的测试
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define TEST_STATIC
const int EXPLICIT_DELETE = 1;
const int MAX_LENGTH = 12;
class Test{
private:
    
    int mounth[MAX_LENGTH];
    int m_a;
    char m_b;
public:
    Test();
    Test(int a, char b);
    Test(Test &);
    ~Test();
    void show();
    int add_a_b();
};

Test::Test()
{
    m_a = 0;
    m_b = 'a';
    cout << "[default constructor] : a new object have been created!" << endl;
}

Test::Test(int a, char b)
{
    m_a = a;
    m_b = b;
    cout << "[int char constructor] : a new object have been created!" << endl;
}

Test::Test(Test& t)
{
    m_a = t.m_a;
    m_b = t.m_b;
    cout << "[Test& constructor] : a new object have been created!" << endl;
}
Test::~Test()
{
    cout << "destruct a object!" << endl;
}
void Test::show()
{
    cout << "m_a : " << m_a << "  m_b : " << m_b << endl;
    return;
}
int Test::add_a_b()
{
    return m_a+m_b;
}


//为函数指针取别名
using functype = void (Test::*)();

// static Test static_item;

int main()
{
#ifndef TEST_STATIC
    Test item7;
    Test item8(8,'t');
    //可以通过下述代码来获取一个类成员函数与类对象的关系
    functype func1 = &Test::show;
    printf("item1.show() address : %p\n",func1);
    //任意一个类对象都可以通过这样的方式来调用其中一个类成员函数而不需要知道调用的是哪个
    (item8.*func1)();

    cout << "直接声明 ：" << endl;
    Test item1;
    Test item2(57,'b');
    Test item3(item2);
    cout << "item1 : ";
    item1.show(); 
    cout << "item2 : ";
    item2.show(); 
    cout << "item3 : ";
    item3.show(); 
    cout << endl << "对象指针 ：" << endl;
    Test* item4 = new Test;
    Test* item5 = new Test(89,'p');
    Test* item6 = new Test(*item5);
    cout << "*item4 : ";
    item4->show(); 
    cout << "*item5 : ";
    item5->show(); 
    cout << "*item6 : ";
    item6->show(); 

    if(EXPLICIT_DELETE)
    {
        //当没有显式调用 delete 来删除 new 出来的对象的时候是不会调用对应的析构函数的
        delete item4;
        delete item5;
        delete item6;
    }
    return 0;
#else
    Test item7;
    Test item6;
    return 0;
#endif
}