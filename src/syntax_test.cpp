#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    bool condition;
    int result = 0;
    cin >> condition;
    if(condition)
        cout << "this is true!" << endl;

    result = condition ? 1:0;
    cout << result << endl;

    int a = 3;
    int &b = a;
    int &c = b;

    cout << "value\ta:" << a << "   b:" << b << "   c:" << c <<endl;
    cout << "address\ta:" << (void*)(&a) << "   b:" << (void*)(&c) << "   c:" << (void*)(&c) <<endl;
    return 0;
}