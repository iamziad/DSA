#ifndef RECURSION_H
#define RECURSION_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Tail Recursion */
static void count_down(int n) {
    if (n < 1)
        return;
    printf("%d\n", n);
    count_down(n - 1);
}

/* Head Recursion */
static void count_up(int n) {
    if (n > 0) {
        count_up(n - 1);
        printf("%d\n", n);
    }
}

static int nested_recursion(int n) {
    if (n > 100) {
        return n - 10;
    } else {
        return nested_recursion(nested_recursion(n + 11));
    }
}

static int sum_of_natural_number_recursive(int n) {
    if (n == 0)
        return 0;
    return sum_of_natural_number_recursive(n - 1) + n;
}

static int sum_of_natural_number_formula(int n) { return n * (n + 1) / 2; }

static int factorial(int n) {
    if (n <= 1)
        return 1;
    return factorial(n - 1) * n;
}

static int pow_linear(int m, int n) {
    if (n == 0)
        return 1;
    return pow_linear(m, n - 1) * m;
}

static double pow_logn(int m, int n) {
    if (n == 0)
        return 1;

    if (n < 0) {
        return 1 / pow_logn(m, -n);
    }

    if (n % 2 == 0) {
        return pow_logn(m * m, n / 2);
    } else
        return pow_logn(m * m, (n - 1) / 2) * m;
}

static double pow_faster_logn(double x, int n) {
    if (n == 0)
        return 1;

    if (n < 0) {
        n = -n;
        x = 1 / x;
    }

    double ret = 1.0;

    for (; n > 0; n /= 2) {
        if (n % 2 == 1) {
            ret *= x;
        }
        x = x * x;
    }
    return ret;
}

/* Taylor Series */
static int e(int n, int d) {
    if (d == 0)
        return 1;

    static int p = 1, f = 1;
    int r;

    r = e(n, d - 1);

    p = p * n;
    f = f * d;

    return r + p / f;
}

/* Terribly Slow O(2^n) */
static int fib(int n) {
  if (n <= 1) return n;

  return fib(n - 2) + fib(n - 1);
}

/* Fast O(n - 2) => O(n) */
static int fib_ite(int n) {
    if (n <= 1) return n;

    int prev_fib = 0, next_fib = 1;

    for (int i = 2; i <= n; i++) {
        int tmp = next_fib;
        next_fib = prev_fib + next_fib;
        prev_fib = tmp;
    }

    return next_fib;
}

/* Fast O(n) - "cache" size must be atleast n + 1 or undefind behaviors may occur */
static int fib_memo(int n, int cache[static n + 1]) {
    if (n <= 1) return n;

    if (cache[n] != -1) return cache[n];

    cache[n] = fib_memo(n - 2, cache) + fib_memo(n - 1, cache);

    return cache[n];
}

/* Fast O(3n) => O(n) */
static int c(int n, int r) {
    int v1 = factorial(n);       /* O(n) */
    int v2 = factorial(r);       /* O(n) */
    int v3 = factorial(n - r);   /* O(n) */

    return v1 / v2 * v3;         /* O(1) */
}

#endif
