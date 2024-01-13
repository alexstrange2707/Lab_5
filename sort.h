#ifndef SORT_H
#define SORT_H

#include "Sub.h"

void bubbleSort(Sub *arr, int n, int(*cmp)(const void*, const void*));
void shellSort(Sub *arr, int n, int(*cmp)(const void*, const void*));

#endif
