#include <stdio.h>

void count_down(int n) {
  if (n < 1)
    return;
  printf("%d\n", n);
  count_down(n - 1);
}