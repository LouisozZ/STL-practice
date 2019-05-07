#include <iostream>
#include <cstdio>

#include <time.h>

class ProgramInfo
{
    protected:
        const int get_line();
        const std::string& get_filename();
        long CurrentTime();
    public:
        ProgramInfo():current_line(-1),file_name("nofile"){};
        ProgramInfo(int line, std::string & filename):current_line(line),file_name(filename){};
        ProgramInfo(int line, const char * filename):current_line(line),file_name(filename){};
        virtual ~ProgramInfo();
    private:
        int current_line;
        std::string file_name;
        void update_info(int line,std::string filename){current_line = line;file_name = filename;};
};

ProgramInfo::~ProgramInfo()
{}

const int ProgramInfo::get_line()
{
    update_info(__LINE__,__FILE__);
    return current_line;
}

const std::string& ProgramInfo::get_filename()
{
    update_info(__LINE__,__FILE__);
    return file_name;
}

long ProgramInfo::CurrentTime()
{
    time_t curenttime;
    localtime(&curenttime);
    return (long)curenttime;
}

class ErrorInfo:private ProgramInfo
{
    public:
        void PrintInfo();
        void SetErrorMsg(int e_num, std::string & e_msg){error_number = e_num; error_msg = e_msg;};
        const int GetErrorNum() const {return error_number;};
        const std::string & GetErrorMsg() const {return error_msg;};

        ErrorInfo():error_msg("default"),error_number(-1){};
        ErrorInfo(int e_num,std::string &e_msg):error_msg(e_msg),error_number(e_num){};
        ErrorInfo(int e_num,const char *e_msg):error_msg(e_msg),error_number(e_num){};
        virtual ~ErrorInfo();
        
    private:
        int error_number;
        std::string error_msg;
};

ErrorInfo::~ErrorInfo(){}

void ErrorInfo::PrintInfo()
{
    using std::cout;
    using std::endl;

    cout << "[ " << CurrentTime() << " ] file: " << get_filename() << "  line: " << get_line() << "\t\t";
    cout << "\"(" << error_number << ") "<< error_msg << "\"" << endl;
    return ;    
}

int main()
{
    int a,b;
    double result;

    std::cin >> a >> b;

    try{
        if(b == 0)
            throw ErrorInfo(5,"test");
        result = a / b;
        std::cout << "finish compute" << std::endl;
    }
    catch (ErrorInfo& error_item)
    {
        error_item.PrintInfo();
        exit(0);
    }

    std::cout << "a / b = " << result << std::endl;
    return 0;
}