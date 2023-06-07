#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "sort_helper.h"


#define MAX_SIZE 1000

/**
 *  parent node
 *  Args:
        i (int): the index of the node
    Returns:
        index of the parent node
*/
int parent(int i) {


    return (i - 1) / 2;
}

/**
 *  left child node
    Args:
        i (int): the index of the node
    Returns:
        index of the left child node   
*/
int left_child(int i) {
    return 2 * i + 1;
}

/**
 * right child node
    Args:
        i (int): the index of the node
    Returns:
        index of the right child node
*/
int right_child(int i) {
    return 2 * i + 2;
}

/**
 *  insert the item at the appropriate position
    Args:
        a (int[]): the array
        data (int): the item to be inserted
        n (int): the number of items in the array
*/
void insert(int a[], int data, int *n) {
    if (*n >= MAX_SIZE) {
        printf("%s\n", "The heap is full. Cannot insert");
        return;
    }
    // first insert the time at the last position of the array 
    // and move it up
    a[*n] = data;
    *n = *n + 1;


    // move up until the heap property satisfies
    int i = *n - 1;
    while (i != 0 && a[parent(i)] < a[i]) {
        swap(&a[parent(i)], &a[i]);
        i = parent(i);
    }
}

/**
 *  heapify the array
    Args:
        a (int[]): the array
        i (int): the index of the node
        n (int): the number of items in the array
*/
void max_heapify(int a[], int i, int n) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // check if the left node is larger than the current node
    if (left <= n && a[left] > a[largest]) {
        largest = left;
    }

    // check if the right node is larger than the current node
    if (right <= n && a[right] > a[largest]) {
        largest = right;
    }

    // swap the largest node with the current node 
    // and repeat this process until the current node is larger than 
    // the right and the left node
    if (largest != i) {
        swap(&a[i], &a[largest]);
        max_heapify(a, largest, n);
    }
}

/**
 *  converts an array into a heap
    Args:
        a (int[]): the array
        n (int): the number of items in the array
*/
void build_max_heap(int a[], int n) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--) {
        max_heapify(a, i, n);
    } 
}

/**
 *  returns the maximum item of the heap
    Args:
        a (int[]): the array
    Returns:
        the maximum item of the heap
*/
int get_max(int a[]) {
    return a[0];
}

/**
 *  deletes the max item and return
    Args:
        a (int[]): the array
        n (int): the number of items in the array
    Returns:
        the maximum item of the heap
*/
int extract_max(int a[], int *n) {
    int max_item = a[0];

    // replace the first item with the last item
    a[0] = a[*n - 1];
    *n = *n - 1;

    // maintain the heap property by heapifying the 
    // first item
    max_heapify(a, 0, *n);
    return max_item;
}

/**
 *  prints the heap
    Args:
        a (int[]): the array
        n (int): the number of items in the array
*/
void print_heap(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d", a[i]);
    }
    printf("\n");
}