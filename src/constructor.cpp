#include <iostream>
#include <memory>
using namespace std;

class D{
    public:
    D(){std::cout << "D constructor" << std::endl;}
    virtual ~D(){std::cout << "D distructor" << std::endl;}
    virtual void function() = 0;
};

class B:virtual public D{
    public:
    B(){std::cout << "B constructor" << std::endl;}
    virtual ~B(){std::cout << "B distructor" << std::endl;}
    void function(){std::cout << "B version" << std::endl;}
};

class C:virtual public D{
    public:
    C(){std::cout << "C constructor" << std::endl;}
    virtual ~C(){std::cout << "C distructor" << std::endl;}
    void function(){std::cout << "C version" << std::endl;}
};

class A: public B,public C{
    public:
    A(){std::cout << "A constructor" << std::endl;}
    ~A(){std::cout << "A distructor" << std::endl;}
    void function(){std::cout << "A version" << std::endl;}
};

class Base_c{
    public:
    Base_c(){cout<<"the default constructor of Base_c"<<endl;}
};

class Derived_c:public Base_c{
    int m_data;
    public:
    //Derived_c(int a):m_data(a){cout << "Derived int"<<endl;}
    //Derived_c(char* num):m_data(atoi(num)){cout << "Derived char*" << endl;}
};

int main()
{
    //Derived_c a(6);
    //Derived_c b("123");
    Derived_c a;
    {
        std::shared_ptr<D> d(new A); 
        //D* d = new A;
        d->function();

        //B* b = (dynamic_cast<A*>(d);
        B b(*dynamic_cast<A*>(d.get()));
        b.function();
    }
        return 0;
}