# C++ 多态形式

<!-- TOC -->
- [C++ 多态形式](#c-多态形式)
  - [函数重载/函数多态](#函数重载函数多态)
  - [运算符重载](#运算符重载)
  - [多态公有继承](#多态公有继承)
    - [在派生类中重新定义方法](#在派生类中重新定义方法)
    - [使用虚函数](#使用虚函数)

## 函数重载/函数多态

参数列表的不同会导致同名的函数产生函数重载，在实际调用的时候会根据参数列表，来选择一个合适的函数来进行调用。

## 运算符重载

运算符重载的通用编码方式及示例说明：

```c++
returntype operator op(argument-list)
//e.g.
type operator +(const type item) const;
type operator +(const int i) const;
friend type operator +(const int i, const type item);
type operator -(const type item);
type operator *(const type item);
type operator [](const type item) const;
//type operator @();   //error!!!

class Test{...};
Test item1,item2,item3;
item1 = item2 + item3; // means to invoke item1=item2.operator+(item3);
item1 = item2 + 3; // means to invoke item1=item2.operator+(3);
item1 = 3 + item2; // means to invoke item1=operator+(3,item2);
```

重载运算符能够让代码逻辑更明了，但是运算符的重载是有限制的：

1. 只能重载已有的运算符。如上述代码中重载 @ 那一行，因为没有运算符 @ 所以这行是错误的，不能重载一个没有的运算符。
2. 重载运算符的参数列表至少要有一个是自定义类型。对于一个二元运算符来说，如果该重载是一个自定义类型的成员函数，则参数列表仅有一个参数，二元运算的第二个操作数就是参数列表中的参数。如果是非成员函数，参数列表中有两个参数，那么至少有一个必须是自定义的，否则会报错，之所以会报错是为了防止用户重载标准类型的运算而导致逻辑错误。
3. 重载运算符的操作数是有顺序的，如果仅仅定义了对象调用的重载运算符，且第二个操作数是一般类型的时候，执行 item + int 是没有问题的，但是如果执行 int + item 就会出错，因为没有对应的函数来解析，所以对于这种情况，应该声明 class operator op(int,class); 为这个 class 的友元函数。 
4. 重载运算符的时候不能改变其原生的句法规则，原本该是二元运算符的不能被修改为一元或其他。拿减号为例，减号既可以作为一元运算符也可以作为二元运算符，一元的时候是在最前面取负号。但是不能将减号作为三元运算符，因为减号没有这种用法。
5. 不能修改运算符的优先级。
6. 不能重载以下运算符
   - sizeof
   - .
   - .*
   - ::
   - ?:
   - 等等
  
    可重载运算符有赋值运算符（=），函数调用运算符（()），下标运算符（[]），通过指针访问类成员运算符（->）等：

    |0|1|2|3|4|5|6|
    |-|-|-|-|-|-|-|
    |1|+|-|*|/|%|^|
    |2|&|\||~=|!|=|<|
    |3|>|+=|-=|*=|/=|%=|
    |4|^=|&=|\|=|<<|>>|>>=|
    |5|<<=|==|!=|<=|>=|&&|
    |6|\|\||++|--|,|->*|->|
    |7|()|[]|new|delete|new[]|delete[]|

 > **注意1：** 对于运算符的重载，拿二元运算符 + 来说，逻辑上而言，是不该修改两个加数的，所以他们应该被声明为 const 类型，对于通过自定义类型象调用的，函数末尾声明 const 以指示调用者不应该被修改。


 > **注意2：** 第二点需要注意的是，如果返回值类型是自定义类型，那么需声明为原生的自定义类型，而非其引用。由第一点注意可知，因为不能修改两个数，所以返回值应该是一个新的对象，保存的是计算结果。那么就需要在运算符载函数里面声明一个新的对象。如果返回值类型是一个引用的话，那么表示的是回的是声明的这个对象本身，但是有一个问题，新的对象在重载函数内部被声明在重载函数退出到达调用函数所在栈帧的时候，在重载函数内部声明的这个变量经被释放了，如果返回的是这个对象本身的话，那么就会出现段错误，访问了已被释放的地址空间。所以返回值类型应该是这个对象本生的类型，这样的话当重函数返回到调用函数栈帧的时候，会生成一个临时对象作为返回值，该临时对象重载函数中声明的对象的副本，当这个返回值对象被赋值给一个接受结果的左值后就会立马自动调用临时变量的析构函数，释放这个对象。为了演示这个过程，代码 [operator.cpp](../../src/operator.cpp) 中，重载了等号运算符并打信息，可以看到这个信息是夹在临时变量的默认构造函数和析构函数之间的。\
 create a new item 0\
 operator =\
 destruct

## 多态公有继承

一个派生类继承了基类的一个方法，但是希望同一个方法在派生类和基类中是不一样的。这个需求的实现就形成了公有继承中接口的一种多态。实现的方法有两种：

1. 在派生类中重新定义方法；
2. 使用虚函数。

### 在派生类中重新定义方法

先来说明第一种，有基类 BaseClass 和公有继承类 DerivedClass ，如果他们都在各自的类定义中定义了相同的方法 function() ，那么他们的对象分别调用的时候，会调用各自的方法， BaseClas::function() , DerivedClass::function()。现在有一个问题，如果这个方法并不是通过一个对象来调用的，而是一个引用或者是一个指针呢？这种情况很常见，不论是一个实参传入到一个引用形参还是通过指针传递对象，这种情况都会出现。对于最普通的情况下，一个派生类的引用引用的是派生类对象，基类引用引用的是基类对象，这种情况下都是没有问题的。不过从[类继承](./类继承.md)中可以知道，基类的引用是可以引用派生类对象的，这个时候就会出现问题：因为这是一个基类的引用，所以这个引用调用的方法是基类的方法，而并非是重新定义的派生类的方法。

在派生类中需要使用基类中的方法时，如果在派生类中没有重载该方法，那么可以直接调用；如果在派生类中重载了该方法，那么要使用的是基类中的方法时，应该在该方法前面加上作用于解析运算符，并用基类类名限定。

### 使用虚函数

为了解决上述的问题，所以就出现了虚函数。如果一个方法在声明的时候声明为虚函数，那么一个引用变量对虚函数的调用会实际调用其所引用对象的函数实现。举个例子：

```c++
//声明的时候，function1 不是虚函数，function2 是虚函数。
BaseClass item_base;
DerivedClass item_derived;

BaseClass &reference1 = item_base;
BaseClass &reference2 = item_derived;

reference1.function1();  // invoke BaseClass::function1()
reference2.function1();  // invoke BaseClass::function1()

reference1.function2();  // invoke BaseClass::function2()
reference2.function2();  // invoke DerivedClass::function2()
```

需要注意的是，如果一个方法在基类中被声明为虚方法，那么在派生类中会自动成为虚方法，所以这里如果不注意的话，可能会产生一些错误，故而建议是在派生类中显式声明虚方法，即对于基类中的虚方法，在派生类中也声明为 virtual 。

结合上述内容，为有继承的基类声明析构函数为虚函数也是有必要的，这样的话，即使使用基类指针或者引用来指向或者引用派生类对象，也能够去调用派生类的析构函数，正确释放对象。

**关键字 virtual 只出现在类声明中，只是为了声明函数原型使用，而不出现在类定义里面。**

[返回主目录](../../README.md)