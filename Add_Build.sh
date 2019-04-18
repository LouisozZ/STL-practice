#!/bin/bash
FILE_EXIST=0
OPTION=
TARGETNAME=
function usage(){
    echo -e "usage : 
    $0 <TARGET>\t\tbuild file whose name is TARGET.cpp and creat a target file named TARGET and then run it
    $0 <TARGET> -r\t\tjust run a target file whoes name is TARGET
    $0 <TARGET> -d\t\tdelete the files related to TARGET and the cmake command about it
    $0 <TARGET> -u\t\trecover TARGET.cpp from deletedcode folder to src folder and then build it
    $0 clean \t\tclean all target files and build files.
    "
}
#检测是否是clean
if [ $# == 1 ]; then
    TARGETNAME=$1
    if [ ${TARGETNAME} == "clean" ]; then
        cd build
        make clean
        exit 0
    elif [ -f src/${TARGETNAME}.cpp ]; then
        #检测文件是否存在
        FILE_EXIST=1
    else
        usage
    fi
elif [ $# == 2 ]; then 
    TARGETNAME=$1
    OPTION=$2
    if [ ${OPTION} != "-u" ] && [ ! -e ./bin/${TARGETNAME} ]; then
        usage
        echo -e "target file ${TARGETNAME} is not existed!\nexit..."
        exit 0
    fi
    case $OPTION in
        "-r")
            ./bin/${TARGETNAME}
            exit 0
            ;;
        "-d")
            rm ./bin/${TARGETNAME}
            mv ./src/${TARGETNAME}.cpp ./deletedcode
            deleteline=`grep -n "${TARGETNAME}" ./src/CMakeLists.txt | awk 'BEGIN {FS=":"} {print $1}'`
            echo -e "while delete line ${deleteline} in ./src/CMakeLists.txt"
            sed -i "${deleteline}d" ./src/CMakeLists.txt
            exit 0
            ;;
        "-u")
            if [ ! -e ./deletedcode/${TARGETNAME}.cpp ]; then
                echo -e "there is no file '${TARGETNAME}.cpp' in ./deletedcode"
                exit 0
            fi
            read -p "Do you want to recover file ${TARGETNAME}.cpp in ./deletedcode? [Y/n]" recover
            if [ ${recover} == "Y" ] || [ ${recover} == "y" ]; then
                mv ./deletedcode/${TARGETNAME}.cpp ./src/
            else
                echo -e "exit..."
                exit 0
            fi
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
if [ "${OPTION}" != "-u" ] && [ ${FILE_EXIST} == 0 ]; then
    echo -e "${TARGETNAME}.cpp not existed ! \nexit build...\n"
    exit 0
fi

# 寻找要编译的目标文件是否已经在编译列表里面
grep "${TARGETNAME}.cpp" CMakeLists.txt >/dev/null

if [ $? == 0 ]; then 
# 找到了一行，则表示已存在，所以不添加
    echo -e "target ${TARGETNAME} have been existed!"
else
# 否则在最后一行添加
    sed -i "\$aADD_EXECUTABLE(${TARGETNAME} ${TARGETNAME}.cpp)" CMakeLists.txt
    echo -e "add \"ADD_EXECUTABLE(${TARGETNAME} ${TARGETNAME}.cpp)\" into src/CMakeLists.txt...\n"
fi

echo -e "now to build ${TARGETNAME}..."
cd ../build && cmake .. && make
if [ $? == 0 ]; then
    echo "--------------------------------------------------"
    echo "file : PROJECT_SOURCE_DIR/src/${TARGETNAME}.cpp"
    echo -e "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n"
    cd ../bin && ./${TARGETNAME}
    echo -e "\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"
    echo "--------------------------------------------------"
fi
exit 0