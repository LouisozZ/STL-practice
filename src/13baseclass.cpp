#include "13baseclass.h"

using namespace usualuse;

baseTest::baseTest():m_str1("liu"),m_str2("wei")
{
}

baseTest::baseTest(string & str1, string &str2)
:m_str1(str1),m_str2(str2)
{
}
