#include <stdio.h>  // Include file for standard input/output
#include <stdlib.h> // so we can use atoi()
#include "heap.c"

/**
 *  test functions in heap.c
*/
int main(int argc, char *argv[])
{
    int a[] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    int n = sizeof(a) / sizeof(a[0]);

    // Before heapify
    printf("Before heapify: ");
    print_heap(a, n);

    // Heapify at index 1
    max_heapify(a, 0, n-1);

    // After heapify
    printf("After heapify: ");
    print_heap(a, n);

    return 0;

}