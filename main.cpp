#include <cmath>
#include <ctime>
#include <iostream>
#include "fib_algs.h"
#include <chrono>
using namespace std::chrono;
using namespace std;

double get_exec_time_in_sec_of_fib_alg(int(*fib_func)(int), int n) {
    auto start = high_resolution_clock::now();
    fib_func(n);
    auto end = high_resolution_clock::now();
    duration<double> elapsed = end - start;
    return elapsed.count();
}

int main() {

    int n = 100;

    double recursive_time = get_exec_time_in_sec_of_fib_alg(fib_recursive, n);
    cout << "Time taken for fib_recursive(" << n << ") = " << recursive_time << " seconds" << endl;

    double iterative_time = get_exec_time_in_sec_of_fib_alg(fib_iterative, n);
    cout << "Time taken for fib_iterative(" << n << ") = " << iterative_time << " seconds" << endl;


    double binary_time = get_exec_time_in_sec_of_fib_alg(fib_binary, n);
    cout << "Time taken for fib_binary(" << n << ") = " << binary_time << " seconds" << endl;


    return 0;
}


