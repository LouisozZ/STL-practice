#include "13baseclass.h"

using namespace usualuse;

BaseClass::BaseClass():m_str1("liu"),m_str2("wei")
{
}

BaseClass::BaseClass(string & str1, string &str2)
:m_str1(str1),m_str2(str2)
{
}
BaseClass::~BaseClass()
{
}

void BaseClass::function1()
{
    cout << "BaseClass function1" << endl;
    return;
}

void BaseClass::function2()
{
    cout << "BaseClass function2" << endl;
    return;
}