#include "mystd.h"

#define OUT 0
#define IN 1

static int *scan(int *returnSize);
static int isword(char c);
static void print(int *table, int size);

int main() {
    int size = 0;
    int *table = scan(&size);
    print(table,size);
    free(table);
}

/* return array allocated by malloc(). caller should free() the space. */
static int *scan(int *returnSize) {
    *returnSize = 20;
    int *table = (int *)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        table[i] = 0;
    }
    int state = OUT;
    char c;
    int len = 0;
    while ((c = getchar()) != EOF) {
        if (isword(c)) {
            if (state == OUT) { state = IN; len = 0; }
            len++;
        } else {
            if (state == IN) {
                if (len < *returnSize) { (table[len])++; }
                state = OUT;
            }
        }
    }
    return table;
}

static int isword(char c) {
    if (c == ' ' || c == '\n' || c == '\t') {
        return 0;
    } else {
        return 1;
    }
}
static void print(int *table, int size) {
    for (int j = 0; j < size; j++) {
        printf("%-3d",table[j]);
    }
    printf("\n");
    for (int i = 10; i >= 0; i--) {
        for (int j = 0; j < size; j++) {
            if (table[j]/10 >= i) {
                printf("|  ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
    for (int j = 0; j < size; j++) {
        printf("%-3d",j);
    }
    printf("\n");
}
