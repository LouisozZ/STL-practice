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

#define print_info() PrintInfo(__LINE__)

class ErrorInfo:private ProgramInfo
{
    public:
        void PrintInfo(int line_num);
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

void ErrorInfo::PrintInfo(int line_num)
{
    using std::cout;
    using std::endl;

    cout << "[ " << CurrentTime() << " ] file: " << get_filename() << "  line: " << line_num << "\t\t";
    cout << "ErrMsg:\"(" << error_number << ") "<< error_msg << "\"" << endl;
    return ;    
}

void throw_msg(){
    throw "test_throw";
    std::cout << "function throw_msg" << std::endl;
    return;
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
        throw_msg();
        std::cout << "after throw_msg" << std::endl;
    }
    catch (ErrorInfo& error_item)
    {
        error_item.print_info();
        exit(0);
    }
    catch (const char *s)
    {
        std::cout << s << std::endl;
    }

    std::cout << "a / b = " << result << std::endl;
    return 0;
}