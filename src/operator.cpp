#include <iostream>

namespace usualuse{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;
};

class Test1{
    private:
        int m_i;
        double m_d;
    public:
        Test1(){using namespace usualuse;m_i = 0; m_d = 0.0;cout << "create a new item "<< m_d << endl;};
        Test1(int i,double d){m_i = i; m_d = d;};
        ~Test1(){using namespace usualuse;cout << "destruct" << endl;};
        Test1 operator +(const Test1 &item) const;
        Test1 operator +(const int i) const;
        Test1 operator +(const double d) const;
        Test1& operator =(const Test1 &item);
        friend Test1& operator +(const int i, const Test1 &item);
        friend Test1& operator +(const double d, const Test1 &item);
        void show();
};
void Test1::show()
{
    using namespace usualuse;
    cout << "m_i = " << m_i << "    m_d = " << m_d << endl;
    return;
}

Test1 Test1::operator +(const Test1 &item) const
{
    Test1 sum;
    sum.m_i = m_i + item.m_i;
    sum.m_d = m_d + item.m_d;
    return sum;
} 

Test1& Test1::operator =(const Test1 &item)
{
    using namespace usualuse;
    cout << "operator = " << endl;
    m_i = item.m_i;
    m_d = item.m_d;
    return *this;
} 

Test1 Test1::operator +(const int i) const
{
    Test1 sum;
    sum.m_i = m_i + i;
    sum.m_d = m_d;
    return sum;
} 

Test1 Test1::operator +(const double d) const
{
    Test1 sum;
    sum.m_d = m_d + d;
    sum.m_i = m_i;
    return sum;
} 

Test1& operator +(const int i, const Test1& item)
{
    Test1 sum;
    sum.m_i = i + item.m_i;
    sum.m_d = item.m_d;
    return sum;
}

Test1& operator +(const double d, const Test1 &item)
{
    Test1 sum;
    sum.m_d = d + item.m_d;
    sum.m_i = item.m_i;
    return sum;    
}

int main()
{
    using namespace usualuse;
    Test1 item1(1,0.1);
    Test1 item2(2,0.2);
    Test1 item3(3,0.3);
    Test1 item4(4,0.4);
    Test1 item5(5,0.5);
    Test1 item6(6,0.6);
    Test1 item_result(10000,10000.0);

    int int_4,int_6,int_8;
    double double_5,double_7,double_9;
    int_4 = 4;
    int_6 = 6;
    int_8 = 8;
    double_5 = 1.5;
    double_7 = 1.7;
    double_9 = 1.9;

    item_result.show();
    item1.show();item2.show();
    item_result = item1 + item2;
    item_result.show();
    item3.show();
    item_result = item3 + 4;
    item_result.show();

}