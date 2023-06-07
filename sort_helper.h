#ifndef SORT_HELPER_H
#define SORT_HELPER_H

#include <stdio.h>

/**
 *  swaps two numbers in an array 
    Args:
        a (int): The 'address of' an index into an array for positions in an array.
        b (int): The 'address of' an index into an array for positions in an array.
    
*/
void swap(int *a, int *b) {
    

    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Prints an array of integers
 * Args:
    array (int[]): The array to be printed
    size (int): The size of the array
*/
void printIntArray(int *array, unsigned int size) {
    unsigned int i; 
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

#endif