#ifndef __13DERIVED_CLASS_H__
#define __13DERIVED_CLASS_H__
#include "13baseclass.h"

class DerivedClass:public BaseClass{
    private:

    public:
        DerivedClass();
        ~DerivedClass();
        void function1();
        virtual void function2();
};

#endif