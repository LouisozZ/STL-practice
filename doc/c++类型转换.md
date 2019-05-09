# C++类型转化运算符

首先来说，C 的所有基础类型转换在 C++ 中照样能用，但是为了使得类型转换更加的规范，C++ 新添加了四个类型转换运算符：

- dynamic_cast \< type-name \>(expression)
- const_cast \< type-name \>(expression)
- static_cast \< type-name \>(expression)
- reinterpret_cast \< type-name \>(expression)

## dynamic_cast\<type-name\>(expression)

该类型转换运算符主要用于在继承链中进行上行和下行类型转换。而这种转换的目的是为了调用虚函数，所以该类型转换运算符的作用类型应该是声明了虚函数的自定义类型，同样也是因为虚函数，其中 type-name 字段的取值应该是指针或者引用。

dynamic_cast 不支持内置类型的转换，可以进行上行和下行转换，但是下行转换时要求基类中至少有一个虚函数，并且只支持指向对象的引用、指针的转换。如果编译器开启了 RTTI ，那么在运行时可以检测当前的转换是否可行，可以的话返回地址，否则返回空指针。也就说明了 dynamic_cast 会对下行转换做运行时类型检测，相较于接下来讲到的 static_cast 做下行转换的时候不做运行时类型检测， dynamic_cast 更安全。

## const_cast\<type-name\>(expression)

这个类型转换运算符可以使得 **const** 变量（表达式）转换为 **非 const** 变量（没有提相互转换是因为非 const 变量可以直接转换为 const 变量）。使用 const_cast 类型转换运算符的时候需要注意一点， type-name 字段的取值，要么是指针，要么是引用，对一个值（变量本身）进行 const 的类型转换结果是未知的。因为对于一个变量，const 限定词的作用域就是保存这个变量值的内存，是这块内存本身的读写属性。而通过引用或者指针指过来的变量， const 属性是加在引用或者指针上的，而没有影响到所指向的变量的读写属性。

有一个简单的例子可以来证明上述的内容：

```c++
const int aa = 5;
const int *const_ptr_aa = &aa;

int *convert_ptr_aa = const_cast<int *>(const_ptr_aa);
*convert_ptr_aa += 1;
cout << "*convert_ptr_aa + 1 = "<< *convert_ptr_aa << endl; //6
cout << "aa = " << aa << endl;  //5
```

首先说说结果，对 convert_ptr_aa 指针所指向内容的修改并没有引起对应 const 变量值的改变。**但是我遇到一个很奇怪的问题，此时我测试了 convert_ptr_aa 指向的地址以及变量 aa 本身的地址，两个地址是相同的，但是他们的值却不同。**

测试代码可以参考 [typeconvert.cpp](../src/typeconvert.cpp)。

对于 const_cast 类型转换运算符，还有一点需要注意的，这个运算符只能转换相同类型的 const 属性，也就是说，type-name 字段的类型必须跟 expression 字段的类型是相同的，否则的话会出错。

## static_cast\<type-name\>(expression)

只有当 type-name 字段的类型能够隐式转换为 expression 字段的类型时，或者是反过来，expression 字段的类型能够隐式转换为 type-name 字段类型的时候，使用 static_cast 来进行类型转换才是正确的，否则将出错。static_cast 可以支持转换内置类型，**这也是四种类型转换运算符中唯一一个能够接受非指针和引用的类型转换运算符。**

static_cast 支持自定义类型的上行和下行类型转换，因为上行转换一定是安全的，所以支持没有任何问题；不过对于下行转换来说，是不安全的，但是 static_cast 并不保证安全性，因为他并没有做运行时类型检测，所以他只保证能够转换，但是转换之后的安全性需要程序员自己来保证。