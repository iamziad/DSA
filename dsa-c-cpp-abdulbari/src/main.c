#include "../include/recursion.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    int cache[8];
    memset(cache, -1, sizeof(cache));
    printf("fib(7) = %d", fib_memo(7, cache));

    return 0;
}
