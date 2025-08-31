#include <stdio.h>

void count_up(int n) {
  if (n > 0) {
    count_up(n - 1);
    printf("%d\n", n);
  }
}
