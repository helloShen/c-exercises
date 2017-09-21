#include "mystd.h"

#define LIM 100

int main(void) {
    char line[LIM];
    char c;
    int i = 0;
    for (i = 0; i < LIM-1; ++i) {
          c = getchar();
          if (c != '\n') {
              if (c != EOF) {
                  line[i] = c;
              } else {
                  break;
              }
          } else {
              break;
          }
    }
    if (c == '\n') { line[i++] = c; }
    line[i] = '\0';
    printf("%s\n",line);
}
