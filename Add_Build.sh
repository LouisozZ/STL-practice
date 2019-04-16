#!/bin/bash
FILE_EXIST=0
function usage(){
    echo -e "usage : 
    ./Add_Build.sh <TARGET>\t\tbuild file whose name is TARGET.cpp and creat a target file named TARGET and then run it
    ./Add_Build.sh -r <TARGET>\t\tjust run a target file whoes name is TARGET
    ./Add_Build.sh -d <TARGET>\t\tdelete the files related to TARGET and the cmake command about it
    "
}
#检测是否是clean
if [ $# == 1 ]; then
    if [ $1 == clean ]; then
        cd build
        make clean
        exit 0
    elif [ -f src/$1.cpp ]; then
        #检测文件是否存在
        FILE_EXIST=1
    else
        usage
    fi
elif [ $# == 2 ]; then 
    if [ ! -e ./bin/$2 ]; then
        usage
        echo -e "target file $2 is not existed!\nexit..."
        exit 0
    fi
    case $1 in
        "-r")
            ./bin/$2
            exit 0
            ;;
        "-d")
            rm ./bin/$2
            rm ./src/$2.cpp
            deleteline=`grep -n "$2" ./src/CMakeLists.txt | awk 'BEGIN {FS=":"} {print $1}'`
            echo -e "while delete line ${deleteline} in ./src/CMakeLists.txt"
            sed -i "${deleteline}d" ./src/CMakeLists.txt
            exit 0
            ;;
        *)
            usage
            exit 0
            ;;
    esac
else
    usage
    exit 0
fi

#检测文件是否存在
cd src
if [ ${FILE_EXIST} == 0 ]; then
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