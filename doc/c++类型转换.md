# C++类型转化运算符

首先来说，C 的所有基础类型转换在 C++ 中照样能用，但是为了使得类型转换更加的规范，C++ 新添加了四个类型转换运算符：

- dynamic_cast \< type-name \>(expression)
- const_cast \< type-name \>(expression)
- static_cast \< type-name \>(expression)
- reinterpret_cast \< type-name \>(expression)

## dynamic_cast\<type-name\>(expression)

该类型转换运算符主要用于自定义类型的上行类型转换。

type-name 字段可填写的类型有：
- 指针
- 引用
- 其他