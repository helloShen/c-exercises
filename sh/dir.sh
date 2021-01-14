#!/bin/sh
#########################################################
#
###############################
######  尝试自动构建路径  #####
###############################
#
# 这这些命令可以动态获取编译需要的几个基本路径:
# ${SH}：此章节编译部署sh脚本根目录
# ${SRC}：此章节源码根目录
# ${BIN}：此章节编译单元，及可执行二进制程序根目录
# ${TEST}：此章节测试测试用例文本文档的根目录
#
# 1. 先通过dirname得到执行脚本所在父级目录
#    比如: /Users/Wei/github/letsplayc/sh/chapter5/
# 
# 2. 把路径中的"sh"替换成"src","bin","test"获得其他根目录
#    /Users/Wei/github/letsplayc/src/chapter5/
#    /Users/Wei/github/letsplayc/bin/chapter5/
#    /Users/Wei/github/letsplayc/test/chapter5/
#
# 注意！不要用source命令导入此脚本，这样$0得到的不是正确的脚本
#
#########################################################


#########################################################
# 终端提示用户路径初始化正在进行
#########################################################
echo "Initialize path params $1..."


#########################################################
# 先通过dirname得到执行脚本所在父级目录
# 比如: /Users/Wei/github/letsplayc/sh/chapter5/
#########################################################
echo '$0='$0
CURR=$(cd $(dirname $0); pwd)
echo "dir.sh is executed at:$ <{$CURR}>"


#########################################################
#把路径中的"sh"替换成"src","bin","test"获得其他根目录
#  /Users/Wei/github/letsplayc/src/chapter5/
#  /Users/Wei/github/letsplayc/bin/chapter5/
#  /Users/Wei/github/letsplayc/test/chapter5/
# 
# shell替换字符串的格式如下：
#   ${string/substring/replacement}
# 这里把"/sh"替换成"/src"
# 
# 注意！一个"/"表示替换一个，两个"//"表示替换所有
# 如果要替换的文本中出现了"/"，要加个转义符用"\/"表示
#########################################################
SH=${CURR}
BIN=${CURR/\/sh/\/bin}
SRC=${CURR/\/sh/\/src}
TEST=${CURR/\/sh/\/test}


#########################################################
# 终端提示用户路径初始化完成
#########################################################
echo "SH=${SH}"
echo "BIN=${BIN}"
echo "SRC=${SRC}"
echo "TEST=${TEST}"
echo "Initialization Finish!"
