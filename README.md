# STL-practice
## 说明
该工程只是为了自学 STL 库而创建。

### 工程目录介绍
```shell
STL-practice
|----bin            #由cmake生成，不用手动创建，保存可执行文件
|----build          #由cmake生成，不用手动创建，build目录
|----deletecode     #执行脚本 -d 选项后源码缓存目录
|----doc            #学习笔记，包括 STL 与 C++基础
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
    ./Add_Build.sh -r <TARGET>          just run a target file whoes name is TARGET
    ./Add_Build.sh -d <TARGET>          delete the files related to TARGET and the cmake command about it
    ./Add_Build.sh -u <TARGET>          recover TARGET.cpp from deletedcode folder to src folder and then build it
    ./Add_Build.sh clean                clean all target files and build files.
```
#### ./Add_Build.sh \<TARGET\>
对于在 src 下新添加了一个测试 .cpp 源文件，直接运行上述命令，会在对应的 CMakeLists.txt 文件中添加对应的编译选项，然后使用 cmake 完成编译，编译完成之后会自动执行。
#### ./Add_Build.sh -r \<TARGET\>
对已存在的目标文件，直接运行，跳过编译过程。
#### ./Add_Build.sh -d \<TARGET\>
删除目标文件，删除对应的编译行，将对应的源码移动到deletedcode文件夹下
#### ./Add_Build.sh -u \<TARGET\>
将 deletedcode 文件夹中与 TARGET 同名的源文件恢复到 src 文件夹下，并添加编译选项，编译执行。
#### ./Add_Build.sh clean
执行 make clean 命令。


## 学习笔记目录
### C++ 基础
[C++模板](./doc/模板.md)\
[构造函数](./doc/构造函数.md)
### STL
