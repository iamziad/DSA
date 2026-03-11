#ifndef RECURSION_H
#define RECURSION_H

#include <stdio.h>

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

#endif
