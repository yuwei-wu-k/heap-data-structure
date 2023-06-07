#ifndef SORTS_H
#define SORTS_H

#include <stdlib.h>
#include "sort_helper.h"
#include "heap.h"

/**
 * sorts an array of integers using the quicksort algorithm
 * Args:
    array (int[]): The array to be sorted
    size (int): The size of the array
    print (int): A flag to indicate whether to print the array after sorting
*/
void quickSortIntegers(int *array, int size, int print) {

    if (size <= 1) {
        return;
    }
    
    int pivot = array[size / 2];
    int i, j;
    for (i = 0, j = size - 1; ; i++, j--) {
        while (array[i] < pivot) {
            i++;
        }
        while (array[j] > pivot) {
            j--;
        }
        if (i >= j) {
            break;
        }
        swap(&array[i], &array[j]);
    }
    quickSortIntegers(array, i, print);
    quickSortIntegers(array + i, size - i, print);
    
    if (print) {
        printIntArray(array, size);
    }
}

/**
 * Sorts an array of integers using the heapsort algorithm
 * Args:
    array (int[]): The array to be sorted
    size (int): The size of the array
    print (int): A flag to indicate whether to print the array after sorting
*/
void heapSort(int *array, int size, int print) {
    
    if (size == 0){
        exit(1);
    }
    for (int i = size / 2 - 1; i >= 0; i--){
        max_heapify(array, size, i);
    }
    
    for (int i = size - 1; i >= 0; i--){
        swap(&array[0], &array[i]);
        max_heapify(array, i, 0);
    }
    
    if (print){
        printIntArray(array, size);
    }
}


#endif