#include <iostream>
using namespace std;

//函数参数为类型参数，由typename关键字声明类型参数
template <typename Type>
int func1(Type t)
{
    cout << "size of func1's parameter is " << sizeof(t) << endl;
    return 0;
}

//函数参数为类型参数，由class关键字声明类型参数。意在说明关键字 typename 和 class 的等同性（于模板而言）
template <class Type>
int func2(Type t)
{
    cout << "size of func2's parameter is " << sizeof(t) << endl;
    return 0;
}

//函数参数及函数返回值为类型参数
template <typename Type>
Type func3(Type t)
{
    Type inner;
    cout << "size of func3's parameter is " << sizeof(t) << endl;
    inner = t + t;
    cout << inner << endl;
    return inner;
}

//函数内部的一个变量类型为类型参数，意在说明模板前缀的作用域
template <typename Type>
void func4(void)
{
    Type inner;
    cout << "size of func4's inner is " << sizeof(inner) << endl;
    return ;
}

int main()
{
    int par_i;
    char par_c;
    long par_l = 4;
    double par_d = 3.0;

    cout << "func1(int): ";
    func1(par_i);
    cout << "func2(int): ";
    func2(par_i);
    cout << "func1(char): ";
    func1(par_c);
    cout << "func2(char): ";
    func2(par_c);

    cout << "func3(4): " << sizeof(func3(par_l)) << " is the result of sizeof(func3()), ";
    par_l = func3(par_l);
    cout << "the func3's result is " << par_l << endl;
    cout << "func4<int>: ";
    func4<int>();
    cout << "func4<char>: ";
    func4<char>();
    cout << "func4<double>: ";
    func4<double>();
    return 0;
}