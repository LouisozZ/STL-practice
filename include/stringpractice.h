#ifndef _STRINGPRACTICE_H_
#define _STRINGPRACTICE_H_
#include <iostream>

namespace usualuse{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::istream;
    using std::ostream;
}

namespace BadString{
    using namespace usualuse;
    class STRing{
        private:
            static int objnum;
            enum {SINGLE_MAX=512};
            char *value;
            int length;
        public:
            STRing();
            STRing(const char *);
            ~STRing();
            void show();
            friend istream& operator >>(istream &, STRing &);
            friend ostream& operator <<(ostream&,const STRing &);
    };

}

namespace OkString{
    using namespace usualuse;
    class STRing{
        private:
            enum {SINGLE_MAX=512};
            static int objnum;
            char *value;
            int length;     //length 是包含了末尾空字符的长度
        public:
            STRing();
            STRing(const char *);
            STRing(const STRing&);
            STRing& operator=(const STRing &);
            friend ostream& operator<<(ostream &, STRing &);
            friend istream& operator>>(istream &, STRing &);
            ~STRing();
    };
    
}
#endif