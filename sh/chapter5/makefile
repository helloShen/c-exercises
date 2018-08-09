#####################################################
#根据此脚本的绝对路径：
#/Users/Wei/github/letsplayc/sh/chapter5
#			     |
#			   替换这个sh文件夹
#
#获取.o和.c和测试用例.txt文件的路径：
#BIN = /Users/Wei/github/letsplayc/bin/chapter5
#SRC = /Users/Wei/github/letsplayc/src/chapter5
#TEST = /Users/Wei/github/letsplayc/test/chapter5
##################################################### 
# 先进入此脚本所在目录
$(shell cd $(shell dirname $0))
# 用pwd获取绝对路径，并用strip函数去除末尾多余空格
# 为什么路径末尾会多出一个空格，还不清楚
ROOT = $(strip $(shell pwd))

# subst函数按模式替换字符串
# $(subst FROM,TO,TEXT): 把字符串TEXT中的FROM字符串替换为TO
BIN = $(subst /sh/,/bin/,$(ROOT))
SRC = $(subst /sh/,/src/,$(ROOT))
TEST = $(subst /sh/,/test/,$(ROOT))


#####################################################
#配置路径和变量
#####################################################
# vpath规定特定类型文件的路径
# 注意！vpath只对依赖规则中的文件有效。对命令行还是无效
vpath %.c $(SRC)
vpath %.o $(BIN)
# 其他变量
CC = gcc
CFLAGS = -I $(SRC)
objects = 5-1.o getch.o


#####################################################
# 依赖规则
# 根据隐含规则，下面的简化规则会展开为： 
#$(BIN)/5-1 : 5-1.o getch.o
	#$(CC) -o $(BIN)/5-1 $(BIN)/5-1.o $(BIN)/getch.o
#$(BIN)/5-1.o : 5-1.c
	#$(CC) -o $(BIN)/5-1.o -c $(SRC)/5-1.c
#$(BIN)/getch.o : getch.c
	#$(CC) -o $(BIN)/getch.o -c $(SRC)/getch.c
#####################################################
$(BIN)/5-1 : $(BIN)/5-1.o $(BIN)/getch.o



#####################################################
#伪目标辅助项
#删除所有编译产生的目标文件以及可执行文件：
#	make cleanall
#只删除目标文件：
#	make cleanobj
#只删除可执行文件：
# 	make cleanexe
#####################################################
# 明确指出所有伪目标
.PHONY : cleanall cleanexe cleanobj

cleanall : cleanexe cleanobj
cleanexe : 
	rm $(BIN)/5-1
cleanobj :
	rm $(BIN)/5-1.o $(BIN)/getch.o
