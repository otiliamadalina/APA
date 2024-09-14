#include <iostream>
#include "fib_algs.h"

using namespace std;

int main() {

    int array[7] = {5, 7, 8, 9, 10, 12, 14};
    for (int i = 0; i < 7; i++) {

        fib_recursive(array[i]);
        cout << endl << "Fibonacci recursiv iteratii: " << iteration_recursive;

        fib_iterative(array[i]);
        cout << endl << "Fibonacci iterativ iteratii: " << iteration_iterative;

        fib_binary(array[i]);
        cout << endl << "Fibonacci calcul binar iteratii: " << iteration_binary;

    }
    return 0;
}


