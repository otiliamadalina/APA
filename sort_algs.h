#ifndef APA_WORK_SORT_ALGS_H
#define APA_WORK_SORT_ALGS_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

extern const int MAX_SIZE;
extern int a[];
extern int b[]; //temp
extern int merged_array[];
extern int n;

extern int merge_iterations;
extern int quick_iterations;

void generate_random_array();

void merge_sort(int left, int right);
void quick_sort(int left, int right);

#endif //APA_WORK_SORT_ALGS_H
