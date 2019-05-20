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
    return 0;
}