#include <iostream>
using namespace std;

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
    return 0;
}