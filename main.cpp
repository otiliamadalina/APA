#include <iostream>
#include "fib_algs.h"
#include <chrono>
#include <iomanip>
using namespace std;

int main() {

    int choice;
    do {
        cout << "\nChoose a number: " << endl;
        cin >> choice;
        std::chrono::time_point<std::chrono::system_clock> start_fib_recursive, end_fib_recursive, start_fib_iterative, end_fib_iterative, start_fib_binary, end_fib_binary;

       cout << "[Iterations]\t[Algorithm]\t[Time(s)]\n-----------------------------------------" << endl;


        //------------------
        start_fib_recursive = std::chrono::system_clock::now();
        fib_recursive(choice);
        cout << iteration_recursive << "\t\tRECURSIVE\t";

        end_fib_recursive = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds_r = end_fib_recursive - start_fib_recursive;
        cout << elapsed_seconds_r.count() << "s\n";


        //------------------
        start_fib_iterative = std::chrono::system_clock::now();
        fib_iterative(choice);
        cout << iteration_iterative << "\t\tITERATIVE\t";

        end_fib_iterative = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds_i = end_fib_iterative - start_fib_iterative;
        cout << elapsed_seconds_i.count() << "s\n";


        //------------------
        start_fib_binary = std::chrono::system_clock::now();
        fib_binary(choice);
        cout << iteration_binary << "\t\tBINARY\t";

        end_fib_binary = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds_b = end_fib_binary - start_fib_binary;
        cout << elapsed_seconds_b.count() << "s\n";

        cout << "-----------------------------------------" << endl;

    } while(choice);

    return 0;
}


