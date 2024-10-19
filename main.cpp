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

    srand(time(NULL));

    printf("Nr of elements: ");
    scanf("%d", &n);

    generate_random_array();

    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }

    clock_t start = clock();
    merge_sort(0, n - 1);
    clock_t end = clock();
    double merge_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nMergeSort: %.6f sec\n", merge_time);
    printf("iter: %d\n", merge_iterations);

    for (int i = 0; i < n; i++) {
        a[i] = b[i];
    }

    start = clock();
    quick_sort(0, n - 1);
    end = clock();
    double quick_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nQuickSort: %.6f sec\n", quick_time);
    printf("iter: %d\n", quick_iterations);

    return 0;

}