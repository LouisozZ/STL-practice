#ifndef _STRINGPRACTICE_H_
#define _STRINGPRACTICE_H_
#include <iostream>

namespace usualuse{
    using std::cin;
    using std::cout;
    using std::endl;
}

namespace BadString{
    class STRing{
        private:
            enum {SINGLE_MAX=512}；
            static int objnum = 0;
            char *value;
            int length;
        public:
            STRing();
            STRing(const char *);
            ~STRing();
            void show();
            friend istream& operator >>(istream &, STRing &);
    }
}

namespace OkString{
    class STRing{
        private:
            static int objnum = 0;
            char *value;
            int length;
        public:
            STRing();
            STRing(const char *);
            STRing(const STRing&);
            friend istream& operatort >>(istream &, STRing &);
            ~STRing();
    }
}
#endif