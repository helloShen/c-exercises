#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/** 打印栈顶元素 */
void printtop(void) {
    if (sp > 0) {
        printf("Top Element: %g\n",val[sp-1]);
    } else {
        printf("Stack is empty!\n");
    }
}

/** 复制栈顶元素 */
double seek(void) {
    if (sp > 0) {
        return val[sp-1];
    } else {
        printf("Stack is empty!\n");
        return 0.0;
    }
}

/** 交换栈顶的两个元素。*/
void swap() {
    if (sp > 1) {
        double temp = val[sp-2];
        val[sp-2] = val[sp-1];
        val[sp-1] = temp;
    }
}

/** 清空栈 */
void clear() {
    sp = 0;
}
