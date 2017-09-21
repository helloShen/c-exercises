#include "mystd.h"

static int *scan(int size);
static void print(int *table, int size);

int main() {
    int size = 26;
    int *table = scan(size);
    print(table,size);
    free(table);
}

/* return array allocated by malloc(). caller should free() the space. */
static int *scan(int size) {
    int *table = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        table[i] = 0;
    }
    int c;
    while ((c = getchar()) != EOF) {
        int offset = c - 'a';
        if (0 <= offset && offset < 26) { table[offset]++; }
    }
    return table;
}

static void print(int *table, int size) {
    for (int j = 0; j < size; j++) {
        printf("%-3d",table[j]);
    }
    printf("\n");
    for (int threshold = 10; threshold >= 0; threshold--) {
        for (int col = 0; col < size; col++) {
            if (table[col]/10 >= threshold) {
                printf("|  ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
    for (int j = 0; j < size; j++) {
        printf("%-3c",j+'a');
    }
    printf("\n");
}
