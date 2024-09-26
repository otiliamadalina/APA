#include <iostream>
#include "fib_algs.h"
#include <chrono>
using namespace std;

int main() {

    int array[7] = {5, 7, 8, 9, 10, 15, 18};
    cout << "Fibonacci [iteratii]:\n" << endl;
    for (int i = 0; i < 7; i++) {

        fib_recursive(array[i]);
        cout << iteration_recursive << "\trecursiv" << endl;

        fib_iterative(array[i]);
        cout << iteration_iterative << "\titerativ" << endl;

        fib_binary(array[i]);
        cout << iteration_binary << "\tcalcul binar" << endl;
        cout << "\n";
    }
    return 0;
}


