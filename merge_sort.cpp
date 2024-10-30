#include "sort_algs.h"

void merge_sort(int left, int right) {
    if (left >= right)
        return;
    else {
        int mid = (left + right) / 2;
        merge_sort(left, mid);
        merge_sort(mid + 1, right);
        int left_i = left;
        int right_i = mid + 1;
        int i = 0;

        while (left_i <= mid && right_i <= right) {
            merge_iterations++;
            if (a[left_i] <= a[right_i])
                merged_array[i++] = a[left_i++];
            else
                merged_array[i++] = a[right_i++];
        }
        while (left_i <= mid) {
            merge_iterations++;
            merged_array[i++] = a[left_i++];
        }
        while (right_i <= right) {
            merge_iterations++;
            merged_array[i++] = a[right_i++];
        }

        for (i = left; i <= right; i++)
            a[i] = merged_array[i - left];
    }
}