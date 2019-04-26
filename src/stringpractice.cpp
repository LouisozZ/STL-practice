#include "stringpractice.h"
#include <cstring>
#include <iostream>

namespace BadString{
    using namespace usualuse;
    int STRing::objnum = 0;
    STRing::STRing()
    {
        objnum += 1;
        cout << "Invoke the default construct function." << endl;
        value = new char [1];
        length =1;
        value[0] = '\0';
    }
    STRing::STRing(const char* input)
    {
        objnum += 1;
        cout << "Invoke the STRing(const char *)."<< endl;
        if (input == nullptr)
        {
            value = new char [1];
            length =1;
            value[0] = '\0';
            return;
        }
        length = strlen(input) + 1;     // 因为 strlen 返回的字符串长度不包含末尾的空字符
        value = new char [length];
        strncpy(value,input,length-1);
        value[length-1] = '\0';      
    }
    STRing::~STRing()
    {
        objnum --;
        cout << "Invoke the distruct function.( "<< objnum << " STRing objects left.)" << endl;
        delete [] value;
        value = nullptr;
    }
    void STRing::show()
    {
        cout << value << " : " << (void*)value<< "\nand the length is :" << length <<endl<<endl;
        return;
    }
    istream& operator >>(istream &ism, STRing &item)
    {
        char tmpvalue[item.SINGLE_MAX];
        ism >> tmpvalue;
        int newlength = strlen(tmpvalue) + 1;
        if(newlength > item.length)
        {
            delete [] item.value;
            item.value = nullptr;
            item.value = new char [newlength];
            item.length = newlength;
            strncpy(item.value, tmpvalue, newlength-1);
            item.value[newlength-1]= '\0';
            return ism;
        }

        item.length = newlength;
        strncpy(item.value, tmpvalue, newlength-1);
        item.value[newlength-1]= '\0';
        return ism;
    }
    ostream & operator << (ostream & osm, const STRing & item)
    {
        osm << item.value;
        return osm;
    }
}

namespace OkString{
    using namespace usualuse;
    int STRing::objnum = 0;
    
}