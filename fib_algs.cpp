#include "fib_algs.h"
using namespace std;

long long int iteration_recursive = 0;
long long int iteration_iterative = 0;
long long int iteration_binary = 0;

long long int fib_recursive(int n) { // O(2^n)

    if (n < 2) {
        iteration_recursive++;
        return n;
    } else {
        iteration_recursive++;
        return fib_recursive(n - 1) + fib_recursive(n - 2);
    }
}

long long int fib_iterative(int n) { // O(n)

    long long int i = 1, j = 0;
    for (long long int k = 1; k <= n; k++) {
        j = i + j;
        i = j - i;
        iteration_iterative++;
    }
    return j;
}

long long int fib_matrix_exp(int n) { // O(log(n))

    long long int i, j, k, h, t;
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


