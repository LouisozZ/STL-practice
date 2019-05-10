#include <iostream>
#include <memory>
#include <vector>
using namespace std;

char Origin[] = "louis chubby lulu do you get your dreaming life?";
char short_str[] = "123";

void Print(string & str)
{
    cout << str << endl;
    return ;
}

int main()
{
    string sa(Origin);
    Print(sa);
    string sb(Origin,7);
    Print(sb);
    string sc(9,'o');
    Print(sc);
    string sd(sa,9,10);
    Print(sd);

    string se(Origin+1,Origin+10);
    Print(se);

    string find_result;
    string find_target("louis");
    int index = sa.find(find_target,0);
    //cout << index << endl;
    if(index != string::npos)
    {
        find_result = string(sa,index,find_target.size());
        Print(find_result);
    }
    else
        cout << "not find " << find_target << endl;

    auto test = {1,2,3,4,5};
    // type of test is initializer_list<int>
    vector<int> vec1 = test;
    vector<int> vec2({2,3,4,5,6});
    vector<int> vec3(test);
    vector<int> vec4{3,4,5,6,7};
    vector<int> vec5 = {4,5,6,7,8};

    for(auto x : vec1) cout << x << " ";
    cout << endl;

    for(auto x : vec2) cout << x << " ";
    cout << endl;

    for(auto x : vec3) cout << x << " ";
    cout << endl;

    for(auto x : vec4) cout << x << " ";
    cout << endl;

    for(auto x : vec5) cout << x << " ";
    cout << endl;
}