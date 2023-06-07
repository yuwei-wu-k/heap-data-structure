/// to compile: clang -Wall tester.c -o tester.out

#include <stdio.h>  
#include <stdlib.h> 
#include <time.h>  
#include "sorts.h"
#include "heap.c"


void (*sorts[])(int *, unsigned int, int) = {
    heapSort,
    quickSortIntegers
    };

/**
 *  Generate a random array of integers
    Args:
        size (int): the size of the array
    Returns:
        int[]: the array of random integers
*/
int *get_random_array(int size) {

    int *random = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        random[i] = rand() % size;
    }
    return random;
}

/**
 *  Sort the array and time it
    Args:
        array (int[]): the array to be sorted
        size (int): the size of the array
        type (int): the type of sort to be used
        print (int): whether or not to print the array
    Returns:
        double: the time it took to sort the array
*/
double sort_and_time(int *array, int size, int type, int print) {
    struct timespec begin, end; // Setup timers
    clock_gettime(CLOCK_MONOTONIC_RAW, &begin); // Get the time before start
    sorts[type](array, size, print);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end); // Get the time after sort
    return (end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
           (end.tv_sec - begin.tv_sec);
}

/**
 *  Main function
    Args:
        argc (int): the number of arguments
        argv (char[]): the arguments
    Returns:
        int: 0 if successful
*/
int main(int argc, char const *argv[]) {
    if (!(argc > 2 && argc < 5)) {
        printf("Two arguments expected, [sort_type] and random size. Add 1 at the end to print out arrays\n");
        printf("[sort_type] 0 == quickSort, 1 == heapSort\n");
        printf("Random size determines the total size of the the random array of numbers to be sorted\n");
        printf("\n");
        printf("Example: ./tester.out 0 1000");
        return 1;
    }

    const int type = atoi(argv[1]);
    if (type > 4) {
        printf("invalid type");
        return 1;
    }

    const int size = atoi(argv[2]); // Convert the argument of the program into an integer

    FILE *csv_file = fopen("sort_times.csv", "w");
    fprintf(csv_file, "size, quickSortIntegers_time, heapSort_time\n");

    // Generate a random seed
    time_t t;
    srand((unsigned)time(&t));

    for (int size = 1000; size < 100000; size += 1000) {
        int *random = get_random_array(size);
        double quick_sort_time = sort_and_time(random, size, 0, 0);
        double heap_sort_time = sort_and_time(random, size, 1, 0);
        fprintf(csv_file, "%d, %f, %f\n", size, quick_sort_time, heap_sort_time);
        free(random);
    }
    
    fclose(csv_file);

    return 0;
}
