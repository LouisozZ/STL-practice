#!/bin/bash
FILE_EXIST=0
OPTION=
TARGETNAME=
SOURCEFILELIST=

declare -i PARANUM=$#
declare -i PARAINDEX

function usage(){
    echo -e "usage : 
    $0 <TARGET>\t\tbuild file whose name is TARGET.cpp and creat a target file named TARGET and then run it
    $0 <TARGET> -l <source file list>\tjust run a target file whoes name is TARGET
    $0 <TARGET> -r\t\tjust run a target file whoes name is TARGET
    $0 <TARGET> -d\t\tdelete the files related to TARGET and the cmake command about it
    $0 <TARGET> -u\t\trecover TARGET.cpp from deletedcode folder to src folder
    $0 clean \t\tclean all target files and build files.
    "
}

function FileExitTest()
{
    if [ -f src/$1.cpp ]; then
        #检测文件是否存在
        FILE_EXIST=1
    else
        echo -e "\nsource file $1.cpp no exit in ./src\n\n"
        usage
        echo -e "\nexit..."
        exit 0
    fi
}
#检测是否是clean
if [ ${PARANUM} == 1 ]; then
    TARGETNAME=$1
    if [ ${TARGETNAME} == "clean" ]; then
        cd build
        make clean
        exit 0
    else
        #检测文件是否存在
        FileExitTest ${TARGETNAME}
        SOURCEFILELIST=${TARGETNAME}.cpp
    fi
else
    PARAINDEX=1
    for paravalue in $@
    do
        if [ ${PARAINDEX} == 1 ]; then
            TARGETNAME=${paravalue}
            FileExitTest ${TARGETNAME}
            SOURCEFILELIST=${TARGETNAME}.cpp
        elif [ ${PARAINDEX} == 2 ]; then
            OPTION=${paravalue}
        elif [ ${PARAINDEX} -gt 2 -a ${OPTION} == "-l" ]; then
            #echo -e "${paravalue}"
            FileExitTest ${paravalue}
            SOURCEFILELIST="${SOURCEFILELIST} ${paravalue}.cpp"
        else
            usage
            exit 0
        fi
        PARAINDEX=${PARAINDEX}+1
    done

    case $OPTION in
        "-r")
            if [ ! -e ./bin/${TARGETNAME} ]; then
                usage
                echo -e "target file ${TARGETNAME} is not existed!\nexit..."
                exit 0
            fi
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
                exit 0
            else
                echo -e "exit..."
                exit 0
            fi
            ;;
        "-l")
            ;;
        *)
            usage
            exit 0
            ;;
    esac
fi

# 寻找要编译的目标文件是否已经在编译列表里面
cd src
grep "ADD_EXECUTABLE(${TARGETNAME}" CMakeLists.txt >/dev/null

if [ $? == 0 ]; then 
# 找到了一行，则表示已存在，所以不添加
    echo -e "target ${TARGETNAME} have been existed!"
else
# 否则在最后一行添加
    sed -i "\$aADD_EXECUTABLE(${TARGETNAME} ${SOURCEFILELIST})" CMakeLists.txt
    echo -e "add \"ADD_EXECUTABLE(${TARGETNAME} ${SOURCEFILELIST})\" into src/CMakeLists.txt...\n"
fi

echo -e "now to build ${TARGETNAME}..."

if [ ! -d ../build ]; then
    mkdir ../build
fi

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