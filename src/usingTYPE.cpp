#include <iostream>
template <typename T>
using type_printf = T (*)(T t);

int int_printf(int input){
    using namespace std;
    cout << "this is a int printf, the input value is "
    << input 
    << ", and the return value is 3." << endl;
    return 3;
}

char char_printf(char input){
    using namespace std;
    cout << "this is a char printf, the input value is "
    << input 
    << ", and the return value is 'a'." << endl;
    return 'a';
}

int main()
{
    using namespace std;
    type_printf<int> first_print = int_printf;
    type_printf<char> second_print = char_printf;
    cout << first_print(78) << " is the function's return value" << endl;
    cout << second_print('k') << " is the function's return value" << endl;
    return 0;
}