#include <iostream>
using namespace std;

int main()
{
    int a = 8;
    int b = 1;
    const int* p = &a;
    //int const *p = &a;
    int * const q = &a;

    p = &b;
    //*p = b;
    //q = &b;
    *q = b;
    return 0;
}