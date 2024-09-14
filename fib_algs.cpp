#include "fib_algs.h"
using namespace std;

long int iteration_recursive = 0;
long int iteration_iterative = 0;
long int iteration_binary = 0;

long long fib_recursive(int n) {
    if (n >= 0 && n <= 1) {
        iteration_recursive++;
        return n;
    }
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

long long fib_iterative(int n) {
    int x = 0, y = 1;
    for (int i = 0; i <= n; i++) {
        y = x + y;
        x = y - x;
        iteration_iterative += 4;
    }
    return y;
}

long long fib_binary(int n) {
    int i, j, k, h, t;
    i = 1;
    j = 0;
    k = 0;
    h = 1;
    iteration_binary += 4;
    while (n > 0) {
        if (n % 2 != 0) {
            t = j * h;
            j = i * h + j * k + t;
            i = i * k + t;
            iteration_binary += 11;
        }
        t = h * h;
        h = 2 * k * h + t;
        k + k * k + t;
        n = n / 2;
        iteration_binary += 11;
    }
    return j;
}


