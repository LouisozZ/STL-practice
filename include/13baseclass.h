#ifndef __13BASE_CLASS_H__
#define __13BASE_CLASS_H__
#include <iostream>

namespace usualuse{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;
};

using namespace usualuse;

class baseTest{
    private:
        string m_str1;
        string m_str2;
    public:
        baseTest();
        baseTest(string & str1, string &str2);
};

#endif