#include "13derivedclass.h"
using namespace usualuse;

DerivedClass::DerivedClass():BaseClass()
{
}

DerivedClass::~DerivedClass()
{
}

void DerivedClass::function1()
{
    cout << "DerivedClass function1" << endl;
    return ;
}

void DerivedClass::function2()
{
    cout << "DerivedClass function2" << endl;
    return;
}