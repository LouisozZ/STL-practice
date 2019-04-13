#!/bin/bash

#把文件从 /src 下移动到与其文件名相同的文件夹下
cd src
test -f $1.cpp
if [ $? != 0 ]; then
    echo -e "$1.cpp not existed ! \nexit build...\n"
    exit 0
fi

mkdir $1 && DIR_HAVE_EXIST=0 && mv_sure=y || DIR_HAVE_EXIST=1
if [ ${DIR_HAVE_EXIST} == 1 ]; then
    read -p "directory $1 have existed, do you want to move $1.cpp into it?[y/n] " mv_sure
else
    echo -e "test ${DIR_HAVE_EXIST}"
fi

if [ ${mv_sure} == "y" ] || [ ${mv_sure} == "Y" ]; then
    mv $1.cpp $1/
    echo -e "have move $1.cpp into /src/$1\n"
else
    echo -e "exit...\n"
    exit 0
fi

# build 该文件
echo -e "now to build $1...\n"
exit 0