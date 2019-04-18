#include <iostream>
//名称空间 louis
namespace louis{
    //在名称空间中定义函数
    bool my_love(std::string name)
    {
        using namespace std;
        cout << name << ", you are my love, and I'll keep you in my heart." << endl;
        if(name == "louis")
            return true;
        return false;
    }
    //在名称空间中声明变量
    int my_age = 24;
    int show_age = 18;
    //在 louis 中定义函数 answer_age()
    int answer_age()
    {
        return show_age;
    }
    //在名称空间中定义类
    class Test{
        private:
            int m_variable_i;
            char m_variable_c;
        public:
            Test(){m_variable_i = 0; m_variable_c = 'a';}
            Test(int a, char b){m_variable_c = b; m_variable_i = a;}
            void show();
    };
}
//名称空间 chubby
namespace chubby{
    int my_age = 16;
    //在 chubby 中定义 answer_age()
    int answer_age()
    {
        return my_age;
    }
}

namespace usual_use{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;
}

//在全局名称空间中，定义 louis 名称空间下，Test 类的成员函数 show()
void louis::Test::show()
{
    //使用 using 声明 std 名称空间下的标识符 cout 和 cin 
    using std::cout;
    using std::endl;
    cout << "the int member is " << m_variable_i;
    cout << "\nthe char member is " << m_variable_c << endl;
    return;
}

//在全局名称空间下定义 answer_age()
int answer_age()
{
    //使用 louis 名称空间下的变量 my_age
    return louis::my_age;
}

int main()
{
    //使用 名称空间::标识符 的方式来使用对应名称空间中的特定标识符
    std::cout << "louis, who is your favorite?" << std::endl;
    std::string louis_answer;
    std::cin >> louis_answer;
    if(louis::my_love(louis_answer))
    {
        std::cout << "how old are you?" << std::endl;
        std::cout << louis::answer_age() << std::endl;
        std::cout << "really? I heard that you are " << answer_age() << std::endl;
    }
    else
    {
        std::cout << "liar!" << std::endl;
    }
    std::cout << "-------------------------\n";
    //一个代码块，建立了一个独立的作用域
    {
        using namespace std;
        using louis::answer_age;
        cout << "using louis::answer_age " << answer_age() << endl;
        {
            //一个新的代码块，新的作用域
            using chubby::answer_age;
            cout << "using chubby::answer_age " << answer_age() << endl;
        }
    }
    //使用 using 声明 louis 名称空间中的标识符answer_age 
    //使用 using 声明 chubby 名称空间中的标识符answer_age 
    //使用 using 编译指令使得 std 名称空间中的标识符在当前作用域下都可见
    using louis::answer_age;
    using chubby::answer_age;
    using namespace std;
    //当一个标识符出现二义性的时候应该显式指定使用哪个名称空间下的标识符
    cout << chubby::answer_age() << endl;
    louis::Test item(18,'d');
    item.show();

    
    {
        using namespace usual_use;
        cout << "this is a new namespace using usual_use" << endl;
        string my_sentences;
        cin >> my_sentences;
        cout << my_sentences;
    }
    return 0;
}