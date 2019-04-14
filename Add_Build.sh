#!/bin/bash

#检测是否是clean
if [ $1 == clean ]; then
    cd build
    make clean
    exit 0
fi
#检测文件是否存在
cd src
test -f $1.cpp
if [ $? != 0 ]; then
    echo -e "$1.cpp not existed ! \nexit build...\n"
    exit 0
fi

# 寻找要编译的目标文件是否已经在编译列表里面
grep "$1.cpp" CMakeLists.txt >/dev/null

if [ $? == 0 ]; then 
# 找到了一行，则表示已存在，所以不添加
    echo -e "target $1 have been existed!"
else
# 否则在最后一行添加
    sed -i "\$aADD_EXECUTABLE($1 $1.cpp)" CMakeLists.txt
    echo -e "add \"ADD_EXECUTABLE($1 $1.cpp)\" into src/CMakeLists.txt...\n"
fi

echo -e "now to build $1..."
cd ../build && cmake .. && make
if [ $? == 0 ]; then
    echo "--------------------------------------------------"
    echo "file : PROJECT_SOURCE_DIR/src/$1.cpp"
    echo -e "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n"
    cd ../bin && ./$1
    echo -e "\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"
    echo "--------------------------------------------------"
fi
exit 0