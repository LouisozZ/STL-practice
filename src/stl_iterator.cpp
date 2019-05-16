#include <iostream>
using namespace std;

template<typename T>
class Test{
    private:
        T m_data;
    public:
        using my_value_type = T;
        T get_value(){return m_data;};
        Test(T data):m_data(data){};
        virtual ~Test(){};
};

template<typename T>
typename T::my_value_type function(T item){
    return item.get_value();
}

int main()
{
    Test<string> item("louis");
    cout << function(item) << endl;
    return 0;
}