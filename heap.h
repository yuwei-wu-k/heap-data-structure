#ifndef _MAXHEAP_H
#define _MAXHEAP_H

int parent(int i);
int left_child(int i);
int right_child(int i);
void swap(int *a, int *b);
void insert(int a[], int data, int *n);
void max_heapify(int a[], int i, int n);
void build_max_heap(int a[], int n);
int get_max(int a[]);
int extract_max(int a[], int *n);

void quickSortIntegers(int *array, int size, int print);
void heapSort(int *array, int size, int print);
void print_heap(int a[], int n);

#endif