# include "mystd.h"

static const char TAB = '\t';
static const char BLANK = ' ';
static const char ENTER = '\n';

static const int TABING = 8;

static void cutline(int n);

int main(void) {
    cutline(10);
}

static void cutline(int n) {
    int nb = 0;
    int nt = 0;
    char c;
    for (int pos = 1; (c = getchar()) != EOF; ++pos) {
        if (c == BLANK) {
            ++nb;
            if (pos % TABING == 0) {
                nb = 0;
                ++nt;
            }
        } else if (c == TAB) {
            nb = 0;
            ++nt;
            pos = (((pos - 1) / TABING) + 1) * TABING;
        } else {
            while (nt > 0) { putchar(TAB); --nt; }
            while (nb > 0) { putchar(BLANK); --nb; }
            putchar(c);
            if (c == ENTER) { pos = 0; }
        }
        if (pos >= n) {
            putchar(ENTER);
            pos = 0; nb = 0; nt = 0;
        }
    }
}
