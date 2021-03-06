# STL-practice

## 说明

该工程只是为了自学 STL 库而创建。

### 工程目录介绍

```shell
STL-practice
|----bin            #由cmake生成，不用手动创建，保存可执行文件
|----build          #由cmake生成，不用手动创建，build目录
|----data           #有关文件输入输出的数据文件
|----deletecode     #执行脚本 -d 选项后源码缓存目录
|----doc            #学习笔记，包括 STL 与 C++基础
  |----picture      #文档中的图片
|----include        #头文件目录，可向其中添加所需头文件，编译时会搜索该目录
|----src            #可向其中添加测试代码
|----.gitignore     #文件内容为git不追踪的目录
|----Add_Build.sh   #工程主要脚本文件，后续详细介绍
|----CMakeLists.txt #工程编译由cmake完成，此为主目录CMakeLists.txt
|----README.md      #本文件
``` 

### Add_Build.sh

一键编译脚本，还提供了额外功能。目标文件名都要求与 src 下源文件同名。

```shell
usage :
    ./Add_Build.sh <TARGET>             build file whose name is TARGET.cpp and creat a target file named TARGET and then run it
    ./Add_Build.sh <TARGET> -l related_file1 related_file2 ...
                                        build file whose name is TARGET.cpp and need complie with other files, then creat a target file named TARGET and then run it
    ./Add_Build.sh <TARGET> -r          just run a target file whoes name is TARGET
    ./Add_Build.sh <TARGET> -d          delete the files related to TARGET and the cmake command about it
    ./Add_Build.sh <TARGET> -u          recover TARGET.cpp from deletedcode folder to src folder and then build it
    ./Add_Build.sh clean                clean all target files and build files.
```

#### ./Add_Build.sh \<TARGET\>

对于在 src 下新添加了一个测试 .cpp 源文件，直接运行上述命令，会在对应的 CMakeLists.txt 文件中添加对应的编译选项，然后使用 cmake 完成编译，编译完成之后会自动执行。

#### ./Add_Build.sh \<TARGET\> -r

对已存在的目标文件，直接运行，跳过编译过程。

#### ./Add_Build.sh \<TARGET\> -d

删除目标文件，删除对应的编译行，将对应的源码移动到deletedcode文件夹下

#### ./Add_Build.sh \<TARGET\> -u

将 deletedcode 文件夹中与 TARGET 同名的源文件恢复到 src 文件夹下，并添加编译选项，编译执行。

#### ./Add_Build.sh clean

执行 make clean 命令。

## 学习笔记目录

### C++ 基础

[C++内存模型](./doc/c++基础/内存模型.md)  
[new 与 delete](./doc/c++基础/有关于new和delete.md)  
[智能内存管理](./doc/c++基础/智能内存管理.md)  
[构造函数](./doc/c++基础/构造函数.md)  
[类继承](./doc/c++基础/类继承.md)  
[友元](./doc/c++基础/友元.md)  
[多态](./doc/c++基础/C++的多态形式.md)  
[C++模板](./doc/c++基础/模板.md)  
[类型转换](./doc/c++基础/c++类型转换.md)  
[const限定符](./doc/c++基础/const限定符.md)  
[异常](./doc/c++基础/异常md)  
[C++11新增特性总结](./doc/c++基础/c++11新增特性总结.md)  

### STL
[STL概念总览](./doc/STL概念总览.md)