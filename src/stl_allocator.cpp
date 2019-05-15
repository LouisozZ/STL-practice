#include <iostream>
#include <vector>

#define ENABLE_TYPE_TRAITS 0

class Test{
    private:
        int x;
    public:
        Test():x(0){std::cout << "++\tinvoke construct." << std::endl;};
        virtual ~Test();
};
Test::~Test()
{
    std::cout << "--\tinvoke destroy." << std::endl;
}

#if ENABLE_TYPE_TRAITS
template<> struct __type_traits<Test>
{
    typedef __true_type     has_trivial_default_constructor;
    typedef __false_type    has_trivial_copy_constructor;
    typedef __false_type    has_trivial_assignment_operator;
    typedef __false_type    has_trivial_destructor;
    typedef __false_type    is_POD_type;
};
#endif

using namespace std;

int main()
{
    vector<int> int_arr = {1,2,3,4,5};
    ptrdiff_t distance1 = int_arr[4] - int_arr[0]; // distance1 = 4
    vector<char> char_arr = {'a','b','c','d','e'};
    ptrdiff_t distance2 = char_arr[4] - char_arr[0]; // distance2 = 4
    cout << "distance1 : " << distance1 << "\ndistance2 : " << distance2 << endl;
    Test item1;
    Test *item2_ptr = new Test;
}