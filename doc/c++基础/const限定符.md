# const 限定符
## const 之于变量
const 限定符的作用是为了限制变量是只读的，防止意外修改。但是对于指针变量而言，const 在 \* 前还是在 \* 后是有所不同的。
```c++
using int_ptr = int *;

int a = 8;

const int* p = &a;          // (*p)     read-only
int * const q = &a;         // q        read-only

const int_ptr p_ptr = &a;   // p_ptr    read-only
int_ptr const q_ptr = &a;   // q_ptr    read-only
```
所以其实究竟是指针本身是一个常量还是指针指向的地址的值是常量，只取决于指针变量声明的时候是否有‘ * ’，如果有，是在‘ * ’的前面还是后面。

如果是后面，则表示指针本身是一个常量，指针的值是不能被修改的，即不能再对指针本身赋值，因为此时只读属性是加载在指针变量上的。

如果是在前面，则表示 (*p) 是一个常量，即指针指向的地址是只读的，只读属性是加载在指针所指向的内存，但同时又是与指针绑定在一起的，只有通过对指针解除引用得到的才是只读属性，而对于其指向的内存处的变量，并非只读。如测试代码 [const.cpp](../../src/const.cpp) 26,27,28行所示。

如果通过别名的方式来新创建了一个类型，那么也只是考虑新类型而不会递归解除别名，如测试代码 [const.cpp](../../src/const.cpp) 13,14,17,18行所示，此时的只读属性仅仅是变量 p_ptr 和 q_ptr 的属性，他们本身的值不能被修改，但是他们所指向的内存是没有只读属性的，所以可以被修改。

## const 之于函数
现有类如下：
```c++
class Test{
    int a;
    public:
        Test(){a = 0;}
        void show(){std::cout<<a;return;}
        void show_with_para(int para){a = para; return;}
};
int main()
{
    const Test item;
    item.show();            //error
    item.show_with_para(3); //error
    return 0;
}
```
此时编译器会报错，因为变量 item 是只读的，不能被修改，但是对 show() 方法的调用是有可能会修改 item 变量的，所以这里编译器会报错。同理适用 show_with_para() 函数。对一个类成员函数，在函数声明和定义中圆括号后面添加 const 关键字来说明这个函数是不会修改调用对象的。
```c++
class Test{
    int a;
    public:
        Test(){a = 0;}
        void show() const {std::cout<<a;return;}
        void show_with_para(int para) const {a = para; return;} //error
};
//或者
class Test{
    int a;
    public:
        Test(){a = 0;}
        void show() const;
        void show_with_para(int para) const;
};
void Test::show() const
{
    std::cout<<a;
    return;
}
void Test::show_with_para(int para) const
{
    a = para;   //error
    return;
}
```
上述代码中 show() 函数是没有问题的，但是 show_with_para(int) 函数的定义会报错，因为当其在声明定义中限制了为 const 属性，此时所有的类成员变量对其都是只读的，不能作为左值被赋值，所以 **a = para** 这一句会报错。

[返回主目录](../../README.md)