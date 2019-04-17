#include<iostream>
using namespace std;
int main()
{
    int* a = new int;
    int* b = new int();
    int* c = new int(0);
    int* d = new int(7);
    int* arr_e = new int [5];
    int* arr_f = new int [5]();
    //int* arr_g = new int [5](0);
    //int* arr_h = new int [5](7);
    cout << "sizeof(int*) = " << sizeof(a) << endl;
    cout << "a : " << *a << endl;
    cout << "b : " << *b << endl;
    cout << "c : " << *c << endl;
    cout << "d : " << *d << endl;
    cout << "arr_e --->" ;
    for(int i = 0; i < 5; i++)
        cout << "  [" << i << "]:"<< arr_e[i];
    
    cout << "\narr_f --->" ;
    for(int i = 0; i < 5; i++)
        cout << "  [" << i << "]:"<< arr_f[i];
    return 0;
}