#include "sort_algs.h"

const int MAX_SIZE = 1000000;
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

    cout << "Nr of elements: ";
    cin >> n;

    generate_random_array();

    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }

    clock_t start_merge, end_merge;
    clock_t start_quick, end_quick;

    start_merge = clock();
    merge_sort(0, n - 1);
    end_merge = clock();
    double merge_time = ((double)(end_merge - start_merge)) / CLOCKS_PER_SEC;

    cout << "\nMerge Sort: \n" << fixed << setprecision(6) << merge_time << " sec\n";
    cout << "iter: " << merge_iterations << "\n";

/*
    start_merge = clock();
    merge_sort(0, n - 1);
    cout << merge_iterations <<endl;
    end_merge = clock() - start_merge;
    cout << (double) end_merge / CLOCKS_PER_SEC << "s." << endl;
*/

    for (int i = 0; i < n; i++) {
        a[i] = b[i];
    }

    start_quick = clock();
    quick_sort(0, n - 1);
    end_quick = clock();
    double quick_time = ((double)(end_quick - start_quick)) / CLOCKS_PER_SEC;

    cout << "\nQuick Sort: \n" << fixed << setprecision(6) << quick_time << " sec\n";
    cout << "iter: " << quick_iterations << "\n";

    return 0;
}