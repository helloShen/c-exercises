#!/bin/sh

#############################################################
# cd $(dirname $0)
# pwd
#
# 这两行脚本是进入shell脚本文件的好习惯，
# 因为大多数时候脚本是从各种奇葩的位置被执行的，
# 此命令可以确保进入到脚本的确切位置，
# 并且取得脚本绝对路径（不包括脚本本身文件名）
#
#
# 例如执行当前脚本的命令为：
# 	sh ./test.sh
# 执行结果显示的是脚本的绝对路径：
# 	/Users/Wei/github/letsplayc/sh/chapter5
#############################################################

#$0: 执行脚本时提供的路径（可能是绝对的也可能是相对的）
#比如：./test.sh
#既包括脚本所在文件夹路径，也包括脚本文件名及扩展名
zero=$0
echo "path=$zero"


#dirname函数负责找出它第一个参数的父级目录
#以脚本路径$0为参数，可以剥离出脚本的父级目录的路径
#比如：sh ./test.sh
#脚本路径$0=./test.sh
#dirname帮我们提取出./这个路径，去掉test.sh这个文件名
dir=$(dirname $0)
echo "dir=$dir"

#cd $(dirname $0): 进入这个目录(切换当前工作目录)
#pwd: 显示当前工作目录的绝对路径
#比如：sh ./test.sh
#$(dirname $0)帮我们过滤出路径./
#cd ./ 相当于进入这个父级目录
#再用pwd打出来的就是这个父级目录的绝对路径
#/Users/Wei/github/letsplayc/sh/chapter5
cd $(dirname $0)
pwd


#$(commend): 获得括号内的命令的输出流
#可以以此将找到的当前文件的绝对路径存在一个变量里
BASEPATH=$(cd $(dirname $0); pwd)

echo $BASEPATH


#############################################################
# 下面是两种方法，分别取路径的父级目录和文件名
# 对于#和##，以及%和%%用法的说明
# ${name%word}
# 从name的尾部开始删除与word匹配的最小部分，然后返回剩余部分
#
# ${name%%word} 
# 从name的尾部开始删除与word匹配的最长部分，然后返回剩余部分
#
# ${name#word}
# 从name的头部开始删除与word匹配的最小部分，然后返回剩余部分
#
# ${name##word}
# 从name的头部开始删除与word匹配的最长部分，然后返回剩余部分
#############################################################
filename="/some/long/path/to/a_file"

# 两种方法取路径的父级目录"/some/long/path/to"
parentdir_v1="${filename%/*}"
parentdir_v2="$(dirname "${filename}")"

# 两种方法区路径的文件名部分"a_file"
basename_v1="${filename##*/}"
basename_v2="$(basename "${filename}")"

echo "${parentdir_v1}"
echo "${parentdir_v2}"
echo "${basename_v1}"
echo "${basename_v2}"


##############################################################
# 取父级目录和文件名最标准的做法
# 注意：
# 这里面的两个横杠--表示后面的字符串不用作命令选项（即使以-开头）
##############################################################
# 标准的取路径的父级目录"/some/long/path/to"
parentdir_std=$(dirname -- "${filename}")
# 标准的取文件名"a_file"
basename_std=$(basename -- "${filename}")



##############################################################
# 参考文献：
# https://unix.stackexchange.com/questions/253524/dirname-and-basename-vs-parameter-expansion
# https://stackoverflow.com/questions/23162299/how-to-get-the-last-part-of-dirname-in-bash
# https://blog.csdn.net/apache0554/article/details/47055827
# https://www.cnblogs.com/xuxm2007/archive/2011/10/20/2218846.html
##############################################################


