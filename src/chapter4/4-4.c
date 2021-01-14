/****************************************************
 * 扩展原始stack.c的功能，添加以下3个功能：
 *      printtop(): 打印栈顶数字
 *      copytop(): 复制栈顶元素
 *      exchtop(): 交换栈顶2个元素
 * 先用stack.h声明原始栈的功能：
 *      push(), pop(), empty()
 * 然后在stackexp.h中导入stack.h，再声明新函数：
 *      printop(),copytop(),exchtop()
 *
 * 需要注意：stack.h中只声明了函数，没有定义变量，
 * 因为在头文件中定义全局变量是一种不好的实践，会重复定义
 * 所以在stackexp.c中用extern关键词调用了外部变量
 ***************************************************/

#include <stdio.h>
#include "stackexp.h"

int main(void) {
    push(1.1);
    push(2.2);

    // printtop()
    printf("printtop: ");
    printtop();

    // copytop()
    printf("printtop: %f\n", copytop());

    // exchtop()
    exchtop();
    printf("after exchtop: ");
    printf("printtop: %f\n", copytop());

    // push()
    push(3.3);
    printf("after push()\n");
    printtop();

    // pop()
    pop();
    printf("after pop()\n");
    printtop();

    // empty()
    empty();
    printf("after empty()\n");
    printtop();
}
