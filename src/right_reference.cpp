#include <iostream>
#include <STL_Practice.h>

using namespace usualuse;

namespace WithRigthReference{
    class Test{
        private:
            int m_length;
            char * m_data;
            static int m_count;

        public:
            Test();
            explicit Test(int n);
            Test(int n, char c);
            Test(const Test &item); //copy
            Test(Test &&item);      //move

            Test & operator=(const Test &item);
            Test & operator=(Test &&item);
            Test operator+(const Test &item);
            void speak();

            friend void ShowItem(Test &item);

            virtual ~Test();
    };

    int Test::m_count = 0;

    void Test::speak()
    {
        if(m_data != nullptr)
            cout << m_data << endl;
        else
            cout << "(null)" << endl;
    }

    void ShowItem(Test &item)
    {
        cout << "length:"<< item.m_length;
        if(item.m_data == nullptr)
            cout <<"\ndata : (null)" << endl << endl;
        else
            cout <<"\ndata : " << item.m_data << endl << endl;
        return ;
    }

    Test::Test():m_length(0),m_data(nullptr)
    {
        m_count++;
        cout << "++\tinvoke default constructor\nAnd now there are "<< m_count << "items" << endl << endl;
    }

    Test::Test(int n)
    {
        m_count++;
        cout << "++\tinvoke (int n) constructor\nAnd now there are "<< m_count << "items" << endl << endl;
        
        if(n > 0)
        {
            m_length = n;
            m_data = new char[m_length];
            for(int index = 0; index < m_length; index++)
                m_data[index] = '-';
            return ;
        }
        m_length = 0;
        m_data = nullptr;
        return;
    }

    Test::Test(int n, char c):m_length(n),m_data(nullptr)
    {
        m_count++;
        cout << "++\tinvoke (int n,char c) constructor\nAnd now there are "<< m_count << "items" << endl << endl;
        
        if(n > 0)
        {
            m_length = n;
            m_data = new char[m_length];
            for(int index = 0; index < m_length; index++)
                m_data[index] = c;
            return ;
        }
        m_length = 0;
        m_data = nullptr;
        return;
    }

    Test::Test(const Test &item)
    {
        m_count++;
        cout << "++\tinvoke (const Test &item) constructor\nAnd now there are "<< m_count << "items" << endl << endl;
        
        //delete [] m_data;
        m_length = item.m_length;
        m_data = new char [m_length];

        for(int index = 0; index < m_length; index++)
            m_data[index] = item.m_data[index];
    }

    Test::Test(Test &&item)
    {
        m_count++;
        cout << "++\tinvoke (Test &&item) constructor\nAnd now there are "<< m_count << "items" << endl << endl;
        
        m_data = item.m_data;
        m_length = item.m_length;

        item.m_length = 0;
        item.m_data = nullptr;
    }

    Test & Test::operator=(const Test &item)
    {
        cout << "==\tinvoke (operator=(const Test &item))\nAnd now there are "<< m_count << "items" << endl << endl;

        if(this == &item)
            return *this;
        delete [] m_data;
        m_length = item.m_length;
        m_data = new char [m_length];

        for(int index = 0; index < m_length; index++)
            m_data[index] = item.m_data[index];
        return *this;
    }

    Test & Test::operator=(Test &&item)
    {
        cout << "==\tinvoke (operator=(Test &&item))\nAnd now there are "<< m_count << "items" << endl << endl;

        if(this == &item)
            return *this;

        m_length = item.m_length;
        m_data = item.m_data;

        item.m_length = 0;
        item.m_data = nullptr;

        return *this;
    }

    Test Test::operator+(const Test &item)
    {
        Test temp_item;
        temp_item.m_length = this->m_length + item.m_length;
        temp_item.m_data = new char [temp_item.m_length];

        int index = 0;

        for(index = 0;index < this->m_length;index++)
            temp_item.m_data[index] = this->m_data[index];
        for(;index < temp_item.m_length;index++)
            temp_item.m_data[index] = item.m_data[index-this->m_length];
        return temp_item;
    }

    Test::~Test()
    {
        cout << "--\t";
        if(m_data == nullptr)
            cout << "temp item ";
        else
            cout << "item \"" << m_data << "\"";
        cout << "invoke distructory" << endl;

        delete [] m_data;
        --m_count;
        cout << "And now there are "<< m_count << "items" << endl << endl;
    }
};

namespace JustLeftReference{
    class Test{
        private:
            int m_length;
            char * m_data;
            static int m_count;

        public:
            Test();
            explicit Test(int n);
            Test(int n, char c);
            Test(const Test &item); //copy

            Test & operator=(const Test &item);
            Test operator+(const Test &item);
            void speak();

            friend void ShowItem(Test &item);

            virtual ~Test();
    };

    int Test::m_count = 0;

    void Test::speak()
    {
        if(m_data != nullptr)
            cout << m_data << endl;
        else
            cout << "(null)" << endl;
    }

    void ShowItem(Test &item)
    {
        cout << "length:"<< item.m_length;
        if(item.m_data == nullptr)
            cout <<"\ndata : (null)" << endl << endl;
        else
            cout <<"\ndata : " << item.m_data << endl << endl;
        return ;
    }

    Test::Test():m_length(0),m_data(nullptr)
    {
        m_count++;
        cout << "++\tinvoke default constructor\nAnd now there are "<< m_count << "items" << endl << endl;
    }

    Test::Test(int n)
    {
        m_count++;
        cout << "++\tinvoke (int n) constructor\nAnd now there are "<< m_count << "items" << endl << endl;
        
        if(n > 0)
        {
            m_length = n;
            m_data = new char[m_length];
            for(int index = 0; index < m_length; index++)
                m_data[index] = '-';
            return ;
        }
        m_length = 0;
        m_data = nullptr;
        return;
    }

    Test::Test(int n, char c):m_length(n),m_data(nullptr)
    {
        m_count++;
        cout << "++\tinvoke (int n,char c) constructor\nAnd now there are "<< m_count << "items" << endl << endl;
        
        if(n > 0)
        {
            m_length = n;
            m_data = new char[m_length];
            for(int index = 0; index < m_length; index++)
                m_data[index] = c;
            return ;
        }
        m_length = 0;
        m_data = nullptr;
        return;
    }

    Test::Test(const Test &item)
    {
        m_count++;
        cout << "++\tinvoke (const Test &item) constructor\nAnd now there are "<< m_count << "items" << endl << endl;
        
        //delete [] m_data;
        m_length = item.m_length;
        m_data = new char [m_length];

        for(int index = 0; index < m_length; index++)
            m_data[index] = item.m_data[index];
    }

    Test & Test::operator=(const Test &item)
    {
        cout << "==\tinvoke (operator=(const Test &item))\nAnd now there are "<< m_count << "items" << endl << endl;

        if(this == &item)
            return *this;
        delete [] m_data;
        m_length = item.m_length;
        m_data = new char [m_length];

        for(int index = 0; index < m_length; index++)
            m_data[index] = item.m_data[index];
        return *this;
    }

    Test Test::operator+(const Test &item)
    {
        Test temp_item;
        temp_item.m_length = this->m_length + item.m_length;
        temp_item.m_data = new char [temp_item.m_length];

        int index = 0;

        for(index = 0;index < this->m_length;index++)
            temp_item.m_data[index] = this->m_data[index];
        for(;index < temp_item.m_length;index++)
            temp_item.m_data[index] = item.m_data[index-this->m_length];
        return temp_item;
    }

    Test::~Test()
    {
        cout << "--\t";
        if(m_data == nullptr)
            cout << "temp item ";
        else
            cout << "item \"" << m_data << "\"";
        cout << "invoke distructory" << endl;

        delete [] m_data;
        --m_count;
        cout << "And now there are "<< m_count << "items" << endl << endl;
    }
};

// using namespace WithRigthReference;
using namespace JustLeftReference;

void function(Test item)
{
    cout << "====================function : ";
    item.speak();
    return ;
}

int main()
{
    

    int x = 9;
    int y = 10;

    int && right_ref = x + y;

    cout << "after initializ :\t" << (void*)(&right_ref) << endl << "value :\t" << right_ref << endl;
    cout << "sizeof(right_reference) = " << sizeof(right_ref) << endl;
    
    // right_ref = 44.6 + 21.1;
    x = 90;
    cout << "after reassigned : \t" << (void*)(&right_ref) << endl << "value :\t" << right_ref << endl;
    cout << "sizeof(right_reference) = " << sizeof(right_ref) << endl;

    {
        Test item1(3,'1');
        Test item2(5,'2');
        // Test item3;
        // item3 = item1;
        // ShowItem(item3);
        // item3 = item1 + item2;
        // ShowItem(item3);
        // Test item4 = item1 + item2;
        // Test item5(item1 + item2);

        Test item6;
        item6 = std::move(item2);

        Test item7 = item1;

        ShowItem(item1);
        ShowItem(item2);
        // ShowItem(item3);
        // ShowItem(item4);
        // ShowItem(item5);
        ShowItem(item6);

        function(item1);
        // function(item5 + item1);
    }

    int rref_a = 0;
    int rref_b = 7;

    cout << "befor std::move";
    cout << "\nrref_a = " << rref_a << ";\t\taddress : " << (void*)(&rref_a);
    cout << "\nrref_b = " << rref_b << ";\t\taddress : " << (void*)(&rref_b);
    cout << endl;

    rref_a = std::move(rref_b);

    cout << "after std::move";
    cout << "\nrref_a = " << rref_a << ";\t\taddress : " << (void*)(&rref_a);
    cout << "\nrref_b = " << rref_b << ";\t\taddress : " << (void*)(&rref_b);
    cout << endl;
    
    
    return 0;
}