#include "fib_algs.h"
using namespace std;

long int iteration_recursive = 0;
long int iteration_iterative = 0;
long int iteration_binary = 0;

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
    int prev_fib = 0, current_fib = 1;
    for (int i = 0; i <= n; i++) {
        current_fib = prev_fib + current_fib;
        prev_fib = current_fib - prev_fib;
        iteration_iterative += 4;
    }
    return current_fib;
}

long long fib_binary(int n) { // O(log n)
    int next_fib_value = 1, fib_n = 0, temp1 = 0, temp2 = 1, intermediate;
    iteration_binary += 4;
    while (n > 0) {
        if (n % 2 != 0) {
            intermediate = fib_n * temp2;
            fib_n = next_fib_value * temp2 + fib_n * temp1 + intermediate;
            next_fib_value = next_fib_value * temp1 + intermediate;
            iteration_binary += 11;
        }
        intermediate = temp2 * temp2;
        temp2 = 2 * temp1 * temp2 + intermediate;
        temp1 = temp1 * temp1 + intermediate;
        n = n / 2;
        iteration_binary += 11;
    }
    return fib_n;
}


