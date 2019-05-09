#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

#include "STL_Practice.h"

using namespace std;

int main()
{
    ostream_iterator<string,char> cout_iter(cout," ;");
    ofstream my_fout(DEF_TO_STR(DATAPATH)"/iterator_in.txt");
    ostream_iterator<string,char> fout_iter(my_fout," ;");

    vector<string> name_list({"louis","xiaopanglu","chubbylu","haohao","zhanshen"});
    copy(name_list.begin(),name_list.end(),cout_iter);

    copy(name_list.rbegin(),name_list.rend(),fout_iter);
    return 0;
}