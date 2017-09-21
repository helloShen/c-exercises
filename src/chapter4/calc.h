#include <math.h>

#define NUMBER '0'  // getop告诉calc下一个拿到的是数字
#define SIN 's'     // getop告诉calc用户调用sin(x)正弦函数
#define EXP 'e'     // getop告诉calc用户调用exp(x)幂函数
#define POW 'p'     // getop告诉calc用户调用pow(x,y)函数

#define SPACE ' '
#define SPOT '.'
#define TAB '\t'
#define ENTER '\n'
#define END '\0'
#define MINUS '-'

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
/** 可以处理负数的getop() */
int modgetop(char s[]);
/** 可以处理sin,exp,pow的getop(). For 4-5.c */
int getop45(char s[]);

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

/** 带有%取模功能的计算器 (in 4-3.c) */
void modcalc(void);

/** 能处理sin(),exp(),pow()函数的计算器(in 4-5.c) */
void calc45(void);
