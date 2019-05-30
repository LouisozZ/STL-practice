#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <deque>
#include <vector>

using namespace std;

template<typename Arg1,typename Arg2,typename Return>
struct LouisFunction:public binary_function<Arg1,Arg2,Return>{
    Return value;
    LouisFunction(Return x):value(x){}
    Return operator()(const Arg1& x,const Arg1& y){return value;}
};

int main()
{
    ostream_iterator<int> outite(cout,"  ");
    int ia[] = {1,2,3,4,5,6,7,8,9};
    int ib[] = {51,52,53,54,55,56,57,58,59};
    deque<int> my_data(ia,ia+9);
    deque<int> my_data2(ib,ib+9);
    deque<int> result_save;
    deque<int> result_save2;
    cout << "origin data1:" << endl;
    copy(my_data.begin(),my_data.end(),outite); cout << endl << endl;
    cout << "origin data2:" << endl;
    copy(my_data2.begin(),my_data2.end(),outite); cout << endl << endl;
    /*===================数值算法=====================*/
    cout << "====accumulate" << endl;
    //==accumulate 默认版本
    cout << "accumulate(default):" << accumulate(my_data.begin(),my_data.end(),0) << endl;
    //==accumulate 仿函数版本
    cout << "accumulate(multilies):" << accumulate(my_data.begin(),my_data.end(),1,multiplies<int>()) << endl;

    cout << endl << "====adjacent_difference" << endl;
    //==微分默认版本
    cout << "adjacent_difference -------default------- with ostream_iterator:" << endl;
    adjacent_difference(my_data.begin(),my_data.end(),outite); cout << endl;
    
    cout << "after adjacent_difference, the origin deque is :"<<endl;
    copy(my_data.begin(),my_data.end(),outite);cout << endl;
    
    cout << "adjacent_difference default with another container:" << endl;
    adjacent_difference(my_data.begin(),my_data.end(),back_inserter(result_save));
    copy(result_save.begin(),result_save.end(),outite); cout << endl;

    //==微分 plus 版本
    cout << "adjacent_difference -------plus------- with ostream_iterator:" << endl;
    adjacent_difference(my_data.begin(),my_data.end(),outite,plus<int>()); cout << endl;

    cout << endl << "====partial_sum" << endl;
    //==积分默认版本
    cout << "partial sum -------default------- with ostream_iterator:" << endl;
    partial_sum(result_save.begin(),result_save.end(),outite); cout << endl;
    
    cout << "after partial sum, the origin deque is :"<<endl;
    copy(result_save.begin(),result_save.end(),outite);cout << endl;
    
    cout << "partial sum default with another container:" << endl;
    partial_sum(result_save.begin(),result_save.end(),back_inserter(result_save2));
    copy(result_save2.begin(),result_save2.end(),outite); cout << endl;

    //==积分 minus 版本
    cout << "partial_sum -------minus------- with ostream_iterator:" << endl;
    partial_sum(result_save.begin(),result_save.end(),outite,minus<int>()); cout << endl;

    //==内积默认版本
    cout << endl << "====inner_product" << endl;
    cout << "inner_product -------default------- :" << endl;
    cout << inner_product(my_data.begin(),my_data.end(),my_data2.rbegin(),0); cout << endl;
    
    cout << "inner_product -------op1=- op2=+------- :" << endl;
    cout << inner_product(my_data.begin(),my_data.end(),my_data2.rbegin(),0,minus<int>(),plus<int>()); cout << endl;

    /*===================基本算法=====================*/    
    //==equal
    cout << endl << "====equal" << endl;
    if(equal(my_data.begin(),my_data.begin() + 6,result_save2.begin()))
        cout << "my_data == result_save2" << endl;
    else 
        cout << "my_data != result_save2" << endl;
    
    if(equal(my_data.begin(),my_data.begin() + 6,result_save2.begin(),LouisFunction<int,int,bool>(false)))
        cout << "my_data == result_save2" << endl;
    else 
        cout << "my_data != result_save2" << endl;
}