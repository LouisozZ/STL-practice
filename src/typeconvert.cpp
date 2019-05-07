#include <iostream>
using namespace std;

int main()
{
    const int a = 5;
    cout << a << endl;
    int b = const_cast<int>(a);
    cout << b << endl;
    b++;
    cout << b << endl;
    return 0;
}