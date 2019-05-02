#include <iostream>
#include "13baseclass.h"
#include "13derivedclass.h"

int main()
{
    BaseClass  item1;
    DerivedClass item2;

    BaseClass &reference1 = item1;
    BaseClass &reference2 = item2;

    reference1.function1();
    reference2.function1();

    reference1.function2();
    reference2.function2();

    return 0;

}