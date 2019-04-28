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
        value[length-1] = '\0';
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
        osm << item.value << " and it at:" << (void*)item.value << endl;
        return osm;
    }
}

namespace OkString{
    using namespace usualuse;
    int STRing::objnum = 0;
    STRing::STRing()
    {
        cout << "Invoke default constructor." << endl;
        objnum++;
        cout << "now there are " << objnum << " items." << endl;
        value = new char [1];
        length = 1;
        value[length-1] = '\0';
    }

    STRing::STRing(const char * input)
    {
        cout << "Invoke STRing(const char *)." << endl;
        objnum++;
        cout << "now there are " << objnum << " items." << endl;
        if(input == nullptr)
        {
            value = new char [1];
            length = 1;
            value[length-1] = '\0';
            return;
        }
        length = strlen(input) + 1;
        value = new char [length];
        strcpy(value,input);
        value[length-1] = '\0';
    }

    STRing::STRing(const STRing& item)
    {
        cout << "Invoke STRing(const STRing&)." << endl;
        objnum++;
        cout << "now there are " << objnum << " items." << endl;
        length = item.length;
        value = new char [length];
        strcpy(value,item.value);
        value[length - 1] = '\0';
    }

    STRing& STRing::operator=(const STRing & item)
    {
        cout << "Invoke operator=(const STRing&)." << endl;
        if(&item == this)
            return *this;
        
        length = item.length;
        delete [] value;
        value = new char [length];
        strcpy(value, item.value);
        value[length - 1] = '\0';
        return *this;
    }

    STRing::~STRing()
    {
        cout << "Invoke distructor." << endl;
        objnum--;
        cout << "now there are " << objnum << " items left." << endl;
        delete [] value;
    }

    ostream& operator<<(ostream &osm, STRing &item)
    {
        osm << item.value << " and it at:" << (void*)item.value << endl;
        return osm;
    }

    istream& operator>>(istream &ism, STRing &item)
    {
        char tmp[item.SINGLE_MAX];
        ism >> tmp;
        int tmplength = strlen(tmp) + 1;
        if(tmplength >= item.length)
        {
            delete [] item.value;
            item.value = new char [tmplength];
            item.length = tmplength;
            strcpy(item.value, tmp);
            item.value[item.length - 1] = '\0';
            return ism;
        }
        
        item.length = tmplength;
        strcpy(item.value,tmp);
        item.value[item.length - 1] = '\0';
        return ism;
    }
    
}