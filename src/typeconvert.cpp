#include <iostream>
using namespace std;

int main()
{
    int a = 8;
    int b = 99;

    const int *const_ptr = &a;
    int *ptr = &b;

    //*const_ptr += 1;      //const_ptr is a const int * ,so error
    *ptr += 1;
    cout << "*ptr + 1 = " << *ptr << endl;

    int *convert_ptr = const_cast<int *>(const_ptr);
    if(convert_ptr != nullptr)
    {
        *convert_ptr += 1;
        cout << "*convert_ptr + 1 = " << *convert_ptr << endl;
    }
    else 
        cout << "const_cast error!" << endl;

    const int *convert_const_ptr = const_cast<int *>(ptr);
    cout << "*convert_const_ptr = " << *convert_const_ptr << endl;

    //*convert_const_ptr += 1;
    cout << "*convert_const_ptr = " << *convert_const_ptr << endl;

    const int aa = 49;
    // int aa = 49;
    cout << "aa's address = \t\t\t" << (void*)(&aa) << endl;

    const int *const_ptr_aa = &aa;
    cout << "const_ptr_aa's address = \t" << (void*)(const_ptr_aa) << endl;
    
    int *convert_ptr_aa = const_cast<int *>(const_ptr_aa);
    cout << "convert_ptr_aa's address = \t" << (void*)(convert_ptr_aa) << endl;
    

    *convert_ptr_aa += 91;
    cout << "after '*convert_ptr_aa += 1;'" << endl;
    cout << "aa = " << aa << endl;
    cout << "*const_ptr_aa = "<< *const_ptr_aa << endl;
    cout << "*convert_ptr_aa = "<< *convert_ptr_aa << endl;
    cout << "aa's address = \t\t\t" << (void*)(&aa) << endl;
    cout << "*const_ptr_aa's address = \t"<< (void*)(const_ptr_aa) << endl;
    cout << "convert_ptr_aa's address = \t" << (void*)(convert_ptr_aa) << endl;

    return 0;
}