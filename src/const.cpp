#include <iostream>
using namespace std;

class Test{
    int a;
    // double asdfa;
    // char dfsdf;
    public:
        Test(){a = 0;}
        void show() const {std::cout<<a;return;}
        void show_with_para(int para) const;
        void show_this_addre(int k, int m, double b) const;
};

void Test::show_with_para(const int para) const
{
    //a = para;
    return ;
}

void Test::show_this_addre(int k, int m, double b) const{
    using std::cout;
    using std::cin;
    using std::endl;
    cout << "\nfirst (int)    : " << &k << endl;
    cout << "second (int)   : " << &m << endl;
    cout << "third (double) : " << &b << endl;
    cout << "this           : " << this << endl;
    cout << "this - &first= : " << ((long)this - (long)(&k)) << endl;
    cout << "sizeof(*this)  : " << sizeof(*this) << endl;
    return;
}

using int_ptr = int *;
int main()
{
    int a = 8;
    int b = 1;

    const int* p = &a;
    //int const *p = &a;
    int * const q = &a;
    const int_ptr p_ptr = &a;
    int_ptr const q_ptr = &b;

    //*p = 5;       //error
    *p_ptr = 9;
    *q_ptr = 7;
    cout << *p_ptr << endl;
    
    p = &b;
    //p_ptr = &b;   //error
    *q = b;


    p = &a;
    a = 4;
    //*p = b;       //error
    //q = &b;       //error
    
    const Test item;
    item.show();
    item.show_with_para(7);
    item.show_this_addre(4,5,6);
    cout << "sizeof(Test) : " << sizeof(Test) << endl;

    return 0;
}

/**
 * 所以其实究竟是指针本身是一个常量还是指针指向的地址的值是常量，
 * 只取决于指针变量声明的时候是否有‘ * ’，如果有，是在‘ * ’的前
 * 面还是后面。
 * 
 * 如果是后面，则表示指针本身是一个常量，指针的值是不能被修改的，
 * 即不能再对指针本身赋值，因为此时只读属性是加载在指针变量上的。
 * 
 * 如果是在前面，则表示 (*p) 是一个常量，即指针指向的地址是只读
 * 的，只读属性是加载在指针所指向的内存，但同时又是与指针绑定在
 * 一起的，只有通过对指针解除引用得到的才是只读属性，而对于其指
 * 向的内存处的变量，并非只读。如26,27,28行所示。
 * 
 * 如果通过别名的方式来新创建了一个类型，那么也只是考虑新类型而
 * 不会递归解除别名，如13,14,17,18行所示，此时的只读属性仅仅是
 * 变量 p_ptr 和 q_ptr 的属性，他们本身的值不能被修改，但是他
 * 们所指向的内存是没有只读属性的，所以可以被修改。
*/