#ifndef __STL_PRACTICE_H__
#define __STL_PRACTICE_H__

#define WORKPATH ..
#define DATAPATH WORKPATH/data

#define DEF_TO_STR1(x) #x
#define DEF_TO_STR(x) DEF_TO_STR1(x)
/**
 * 宏定义说明：
 * 对于没有 # ## 的宏定义，当包含别的宏定义的时候会自动完全展开，这也是为什么需要两层来完成字符串转换
 * #    ：  字符串化（双引号），x -> "x"  1.忽略 x 前后空格；2.x 中间有空格，只保留一个
 * ##   ：  连接， ## 两边的空格可有可无
 * @#   ：  字符化（单引号）， x -> 'x'
*/

namespace usualuse{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;
};

#endif