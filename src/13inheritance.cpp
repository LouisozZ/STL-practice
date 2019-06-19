#include <iostream>
#include "13baseclass.h"
#include "13derivedclass.h"

class new_base{
    private:
        int m_a;
        std::string m_data;
        virtual void my_private_print(std::string msg){std::cout << msg << std::endl;}
    public:
        new_base(int a = 1, std::string data = "base"):m_a(a),m_data(data){std::cout << "invoke base constructor" << std::endl;}
        inline virtual void show(){std::cout << "---------base class\na : " << m_a << std::endl <<"data : " << m_data << std::endl;}
        virtual ~new_base(){std::cout << "base deconstructor" << std::endl;m_data.std::string::~string();}
        void my_print(std::string msg = "base default message"){my_private_print(msg);}
};

class new_derived:public new_base{
    private:
        int m_age;
        virtual void my_private_print(std::string msg){std::cout << msg << std::endl << "invoked in the derived class" << std::endl;}
    public:
        new_derived(int age = 18,int a = 99,std::string data = "derived"):new_base(a,data),m_age(age){std::cout << "invoke derived constructor" << std::endl;}
        ~new_derived(){std::cout << "derived deconstructor" << std::endl;}
        inline void show(){std::cout << "---------derived class\nm_age : " << m_age << std::endl;}
        virtual void virtual_derived_show(){std::cout << "---------derived class\na derived's virtual."<<std::endl;}
        void nonvirtual_derived_show(){std::cout << "---------derived class\na derived's nonvirtual."<<std::endl;}
};


int main()
{
    new_base base1;
    new_derived derived1;

    base1.my_print();
    derived1.my_print("a new message");

    new_base *b_ptr = new new_base;
    b_ptr->my_print();

    delete b_ptr;

    b_ptr = new new_derived;
    b_ptr->my_print("second message");
    delete b_ptr;

    // base1.show();

    // derived1.show();
    // derived1.virtual_derived_show();
    // derived1.nonvirtual_derived_show();
    // std::cout << "=======================" << std::endl;
    // new_base *base_ptr = new new_derived(24);

    // base_ptr->show();
    //base_ptr->virtual_derived_show();
    //base_ptr->nonvirtual_derived_show();

    // BaseClass  item1;
    // DerivedClass item2;

    // BaseClass &reference1 = item1;
    // BaseClass &reference2 = item2;

    // reference1.function1();
    // reference2.function1();

    // reference1.function2();
    // reference2.function2();

    // item2.BaseClass::function1();
    // item2.function1();

    // return 0;

}