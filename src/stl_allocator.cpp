#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> int_arr = {1,2,3,4,5};
    ptrdiff_t distance1 = int_arr[4] - int_arr[0]; // distance1 = 4
    vector<char> char_arr = {'a','b','c','d','e'};
    ptrdiff_t distance2 = char_arr[4] - char_arr[0]; // distance2 = 4
    cout << "distance1 : " << distance1 << "\ndistance2 : " << distance2 << endl;
}