#include "fib_algs.h"
using namespace std;

long long iteration_recursive = 0;
long long iteration_iterative = 0;
long long iteration_binary = 0;

long long fib_recursive(int n) { // O(2^n)

    if (n < 2) {
        iteration_recursive++;
        return n;
    } else {
        iteration_recursive++;
        return fib_recursive(n - 1) + fib_recursive(n - 2);
    }
}

long long fib_iterative(int n) { // O(n)

    long long i = 1, j = 0;
    for (long long k = 1; k <= n; k++) {
        j = i + j;
        i = j - i;
        iteration_iterative++;
    }
    return j;
}

long long fib_binary(int n) {

    long long i, j, k, h, t;
    i = 1;
    j = 0;
    k = 0;
    h = 1;

    while (n > 0) {
        iteration_binary++;
        if (n % 2 == 1) {
            t = j * h;
            j = (i * h) + (j * k) + t;
            i = (i * k) + t;
        }
        t = h * h;
        h = (2 * k * h) + t;
        k = (k * k) + t;
        n = n / 2;
    }
    return j;
}


