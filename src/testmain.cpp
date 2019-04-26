#include <iostream>
#include "stringpractice.h"

using namespace BadString;
using namespace usualuse;

int main()
{
    STRing item1("this is item1");
    STRing item2;

    cout << "cin a string to assignment item2" << endl;
    cin >> item2;

    STRing item3;
    item3 = item2;

    cout << "now to show the result:" << endl;
    cout << "item1 :" << item1 << endl;
    cout << "item2 :" << item2 << endl;
    cout << "item3 :" << item3 << endl;

}