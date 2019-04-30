#include <iostream>
#include "stringpractice.h"

using namespace OkString;
using namespace usualuse;

const int& function(const int &i)
{
    return i;
}

class Test{
    private:
        const int m_ad;
        // int m_ad;
        int print;
    public:
        Test(int ad);
        Test(Test &test);
        Test();
        void show();
        // Test& operator=(Test&);
};
Test::Test(int ad):m_ad(ad)
{
    print = 28;
};
Test::Test(Test &test):m_ad(test.m_ad)
{
    print = 28;
};
Test::Test():m_ad(0)
{
    print = 0;
}
// Test& Test::operator=(Test& input)
// {
//     if(this == &input)
//         return *this;
//     print = input.print;
//     m_ad = input.m_ad;
//     return *this;
// }
void Test::show()
{
    cout << "m_ad : "<< m_ad << endl;
    return;
}

int main()
{
    STRing item1("this is item1");
    STRing item2;

    cout << "cin a string to assignment item2" << endl;
    cin >> item2;

    STRing item3 = item2;
    //item3 = item2;

    cout << "now to show the result:" << endl;
    cout << "item1 :" << item1;
    cout << "item2 :" << item2;
    cout << "item3 :" << item3;

    int result,input;
    double dddd;
    input = 1;
    dddd = 0.6; 

    result = function(input);
    cout << result << endl;
    result += 1;
    cout << result << endl;
    cout << input << endl;

    Test test1(34);
    test1.show();
    // test1 = Test(21);
    // test1.show();
    Test test2 = test1;
    test2.show();

    return 0;

}