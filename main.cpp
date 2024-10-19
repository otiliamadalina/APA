#include "sort_algs.h"

const int MAX_SIZE = 100000;
int a[MAX_SIZE];
int b[MAX_SIZE];
int merged_array[MAX_SIZE];
int n = 0;

int merge_iterations = 0;
int quick_iterations = 0;

void generate_random_array() {
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }
}

int main() {
    srand(time(nullptr));
    int choice;

    do {
        cout << "\nChoose a number of elements: ";
        cin >> n;

        generate_random_array();

        for (int i = 0; i < n; i++) {
            b[i] = a[i];
        }

        auto start = chrono::high_resolution_clock::now();
        merge_sort(0, n - 1);
        auto end = chrono::high_resolution_clock::now();
        double merge_time = chrono::duration<double>(end - start).count();

        cout << "\n[Iterations]\t[Algorithm]\t[Time(s)]\n";
        cout << "---------------------------------------------------------\n";
        cout << merge_iterations << "\t\tMERGE SORT\t" << fixed << setprecision(6) << merge_time << "s" << endl;

        for (int i = 0; i < n; i++) {
            a[i] = b[i];
        }

        start = chrono::high_resolution_clock::now();
        quick_sort(0, n - 1);
        end = chrono::high_resolution_clock::now();
        double quick_time = chrono::duration<double>(end - start).count();

        cout << quick_iterations << "\t\tQUICK SORT\t" << fixed << setprecision(6) << quick_time << "s" << endl;
        cout << "---------------------------------------------------------\n";

    } while (choice != 0);

    return 0;
}