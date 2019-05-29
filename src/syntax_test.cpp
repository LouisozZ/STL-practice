#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

class my_test{
    int & m_data;
    public:
    void show(){cout<<m_data<<endl;}
    my_test(int &a):m_data(a){cout << "my_test(int &)" <<endl;};
    //my_test(){int a = 6;m_data = a;};
};

int main(int argc, char *argv[])
{
    bool condition;
    int result = 0;
    cout << "cin the condition value:" << endl;
    cin >> condition;
    if(condition)
        cout << "this is true!" << endl;

    result = condition ? 1:0;
    cout << result << endl;

    int a = 3;
    int &b = a;
    int &c = b;

    my_test item(a);

    item.show();

    a = 10;
    item.show();

    cout << "value\ta:" << a << "   b:" << b << "   c:" << c <<endl;
    cout << "address\ta:" << (void*)(&a) << "   b:" << (void*)(&c) << "   c:" << (void*)(&c) <<endl;

    int ia[] = {1,2,3,4,5};
    deque<int> id(ia,ia+5);

    int ib[] = {21,22,23};
    copy(ib,ib+3,back_inserter(id));    //id : 1,2,3,4,5,21,22,23
    copy(ib,ib+2,front_inserter(id));   //id : 22,21,1,2,3,4,5,21,22,23
    auto itr = find(id.begin(),id.end(),22);
    copy(ia+2,ia+4,inserter(id,itr));

    for(auto temp_itr = id.begin();temp_itr != id.end();temp_itr++)
        cout << *temp_itr << " ";
    cout << endl;

    cout << "the test of cin" << endl << "======================" << endl;
    int temp_data = 0;
    bool test_cin_result = false;

    test_cin_result = cin ? true:false;
    if(test_cin_result)
        cout << "init cin is true." << endl;
    else
        cout << "init cin is false." << endl;
        
    for(int i = 0;test_cin_result;i++)
    {
        cin >> temp_data;
        cout << "cin a number, the value is :" << temp_data << endl;
        test_cin_result = cin ? true:false;
        if(test_cin_result)
            cout << "["<<i<<"] cin is true." << endl;
        else
            cout << "["<<i<<"] cin is false." << endl;
    }
    
    cout << "======================" << endl;

    istream_iterator<char> inite(cin),eos;
    cout << "cin result :  "<< *inite << endl;
    for(;inite!= eos;inite++){
        cout << *inite << "  ---" << endl;
    }
    cout << "get a eos." << endl;
    //eos++;
    //++eos;
    //cout <<"["<< *eos << "]   got value" << endl;
    //++inite;
    cin >> temp_data;
    for(;inite!= eos;inite++){
        cout << *inite << "  ---" << endl;
    }
    if(inite == eos)
        cout << "inite == eos; and the *inite = "<< *inite << endl;
    return 0;
}