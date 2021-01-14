/**
 * 逆波兰计算器包需要的函数以及他们之间通信需要遵守协议
 * 注：
 * 不需要包含<stdio.h>和<stdlib.h>这些基础包。因为这两个基础包逻辑上不属于计算器包。
 * 他们提供的服务不属于boolcalc.h包服务的一部分。
 * 在需要这两个基础包的源文件的地方再引入。
 */


/**
 * bootcalc.c和bootgetop.c之间的通信协议
 */
#define NUMTOOLONG 0                    // getop()返回0，表示操作数太长，超过给出的数组长度
#define NUM 1                           // getop()返回1，代表下一个读到的是操作数
#define MAXSIZE 10                      // getop()接受的参数数组s的大小


/**
 * 包内的主要函数
 */
// bootcalc.c
void enter(void);                       // 跳过此行，计算下一行
// bootgetop.c
int getop(char s[]);                    // 取下一个操作数，或操作符号
// bootgetch.c
int getch(void);                        // 读取下一个字符（带缓冲区）
void ungetch(int i);                    // 往缓冲区塞回刚才读取的字符
// bootstack.c
int isFull();                           // 检查计算栈是否已满
void push(double d);                    // 压一个操作数进计算栈（之前必须调用isFull()检查）
int isEmpty();                          // 检查计算栈是否为空
double pop(void);                       // 弹出计算栈顶部操作数（之前必须调用isEmpty()函数检查）
void empty(void);                       // 清空计算栈
