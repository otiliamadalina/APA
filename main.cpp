#include <iostream>
#include "fib_algs.h"
#include <ctime>
using namespace std;

int main() {

    clock_t start_1, finish_1;
    clock_t start_2, finish_2;
    clock_t start_3, finish_3;

    long long fib1;
    long long fib2;
    long long fib3;

    int choice;
    do {
        cout << "\nChoose a number: ";
        cin >> choice;

        cout << "\n[Iterations]\t[Algorithm]\t[Time(s)]\t[Number]\n---------------------------------------------------------" << endl;

        //------------------ Recursive Fibonacci ------------------

        start_1 = clock();
        fib1 = fib_recursive(choice);
        cout << iteration_recursive << "\t\tRECURSIVE\t";
        finish_1 = clock() - start_1;
        cout << (float) finish_1 / CLOCKS_PER_SEC << "s.\t\t" << fib1 << endl;

        //------------------ Iterative Fibonacci ------------------

        start_2 = clock();
        fib2 = fib_iterative(choice);
        cout << iteration_iterative << "\t\tITERATIVE\t";
        finish_2 = clock() - start_2;
        cout << (float) finish_2 / CLOCKS_PER_SEC << "s.\t\t" << fib2 << endl;

        //------------------ Binary Fibonacci ------------------

        start_3 = clock();
        fib3 = fib_binary(choice);
        cout << iteration_binary << "\t\tBINARY\t\t";
        finish_3 = clock() - start_3;
        cout << (float) finish_3 / CLOCKS_PER_SEC << "s.\t\t" << fib3 << endl;

        cout << "---------------------------------------------------------" << endl;

    } while(choice);

    return 0;
}


