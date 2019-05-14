#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>

#include "STL_Practice.h"

using namespace usualuse;
using namespace std;

class Function{
    int dividend;
    public :
        Function():dividend(1){};
        Function(int div):dividend(div){};
        bool operator()(int divisor);
};

bool Function::operator()(int divisor)
{
    return divisor%dividend;
}

int main()
{
    ostream_iterator<string,char> cout_iter(cout," ;");
    ofstream my_fout(DEF_TO_STR(DATAPATH)"/iterator_in.txt");
    ostream_iterator<string,char> fout_iter(my_fout," ;");

    vector<string> name_list({"louis","xiaopanglu","chubbylu","haohao","zhanshen"});
    copy(name_list.begin(),name_list.end(),cout_iter);

    copy(name_list.rbegin(),name_list.rend(),fout_iter);

    Function mod3(3);
    int looptimes = 5;
    vector<int> divisor = {13,35,66,22,99};
    while(looptimes--)
    {
        if(!mod3(divisor[looptimes]))
            cout << divisor[looptimes] << " % 3" << " = true" << endl;
        else
            cout << divisor[looptimes] << " % 3" << " = false" << endl;
    }

    Function mod13(13);
    looptimes = 5;
    while(looptimes--)
    {
        if(!mod13(divisor[looptimes]))
            cout << divisor[looptimes] << " % 13" << " = true" << endl;
        else
            cout << divisor[looptimes] << " % 13" << " = false" << endl;
    }
    auto my_fun = [&,looptimes](int x) ->double {cout << "test " << x << endl;return 3;};
    for_each(divisor.begin(),divisor.end(),[](int x){cout << x << " ";});
    return 0;
}