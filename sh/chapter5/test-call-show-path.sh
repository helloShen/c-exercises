#!/bin/sh

# 直接调用脚本（开一个新shell执行）
# 结果："../test-show-path.sh"
sh ../test-show-path.sh

# 相当于把脚本导入本地脚本中（在本地shell中执行）
# 结果："call-test-show-path.sh"
#source ../test-show-path.sh

# 可以得到"test-show-path.sh"所在的绝对路径
#BASE=$(sh ../test-show-path.sh)
#echo "Absolute Root = ${BASE}"


