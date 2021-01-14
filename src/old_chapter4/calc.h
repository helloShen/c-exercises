#include <math.h>

/** getop() 返回的读到的操作符类型 */
#define NUMBER '0'  // getop告诉calc下一个拿到的是数字
#define FUNC '1'    // getop告诉calc下一个拿到的是sin()，exp()，pow()这样的函数
#define VAR '2'     // getop告诉calc下一个拿到的是变量符号
#define RIG '3'     // getop告诉calc在寄存器中缓存前一个计算的结果

/**
 * 能处理的三种简单函数的代号
 * 只在4-5.c和getop45.c里使用
 * 到了4-6.c和getop46.c里改成返回FUNC表示读到了函数操作符
 */
#define SIN 's'     // getop告诉calc用户调用sin(x)正弦函数
#define EXP 'e'     // getop告诉calc用户调用exp(x)幂函数
#define POW 'p'     // getop告诉calc用户调用pow(x,y)函数

/** 一些常用的符号 */
#define SPACE ' '
#define SPOT '.'
#define TAB '\t'
#define ENTER '\n'
#define END '\0'
#define MINUS '-'
#define EQUAL '='

/**
 * getch.c 读取字符服务的接口
 */
int getch(void);        // 读取下一个字符
void ungetch(int c);    // 自带缓存区，可以放回多读的字符

/**
 * getop.c 模块对外服务的接口
 * 读取下一个操作数，或操作符
 *      若读到一个操作数，装在参数s数组中返回
 *      若读到操作符，直接通过返回值返回
 * getop依赖getch
 */
int getop(char s[]);
/** 练习4-3：可以处理负数的getop(). (For 4-3.c) */
int modgetop(char s[]);
/** 练习4-5：可以处理sin,exp,pow的getop(). For 4-5.c */
int getop45(char s[]);
/** 练习4-6：能使用变量[A-Z]和缓存前一行计算结果（使用寄存v）的计算器（For 4-6.c） */
int getop46(char s[]);

/**
 * stack.c是最简单的栈操作接口，只有入栈和出栈两个基本操作
 */
void push(double num);  // 压入栈
double pop(void);       // 弹出栈
/**
 * stackexp.c 栈容器的扩展补丁
 */
void printtop(void);    // 打印栈顶元素
double seek(void);      // 复制栈顶元素
void swap();            // 交换栈顶的两个元素
void clear();           // 清空栈

/**
 * calc.c是标准版的加减乘除计算器
 * calc依赖getch,getop和stack的服务
 * calc.main()函数可以作为主入口
 */
void calc(void);

/** 练习4-4： 带有%取模功能的计算器 (in 4-3.c) */
void modcalc(void);

/** 练习4-5：能处理sin(),exp(),pow()函数的计算器(in 4-5.c) */
void calc45(void);

/** 练习4-6：能使用变量[A-Z]和缓存前一行计算结果（使用寄存v）的计算器（in 4-6.c） */
void calc46(void);
