#include "sort_algs.h"

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int left, int right) {
    int pivot = b[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        quick_iterations++;
        if (b[j] <= pivot) {
            i++;
            swap(&b[i], &b[j]);
        }
    }
    swap(&b[i + 1], &b[right]);
    return i + 1;
}

void quick_sort(int left, int right) {
    if (left < right) {
        int pivot_i = partition(left, right);
        quick_sort(left, pivot_i - 1);
        quick_sort(pivot_i + 1, right);
    }
}