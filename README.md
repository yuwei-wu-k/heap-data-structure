# Research Paper
Name: Yuwei Wu

Semester: 2nd Semester 2023

Topic: heap data structure

Link The Repository: https://github.com/Spring23-CS5008-BOS-Lionelle/research-project-yuwei-wu-k.git


## Introduction
This report focuses on heap data structure and heapsort. It tries to compare the heapsort and other sorting algorithms such as quicksort to analyze which algorithm may be more appropriate for a given application or dataset.

The heap data structure is a tree-based data structure mainly used for a priority queue <sup>[5]</sup>. It is a complete binary tree of two types: max-heap and min-heap.

![binary_heap] <sup>[8]</sup>.

Each node has a value that is greater than or equal to (in a max heap) or less than or equal to (in a min heap) the values of its children. This property ensures that the root node of the heap is always the maximum (or minimum) element in the heap, making it an ideal data structure for implementing priority queues.

![heap_type] 

The heap data structure was first introduced by J. W. J. Williams(1964) as a data structure for the heapsort sorting algorithm <sup>[1]</sup>. 


## Analysis of Data structure
Heap operations are efficient because the height of a heap is logarithmic with respect to the number of elements. 

| function | Time Complexity | Space Complexity |
| :-- | :-- |  :-- |
| Insert  | $O(\log n)$ | $O(1)$ |
| Deletion | $O(\log n)$  | $-$ |
| Peek | $O(1)$ | $-$ |
| Heap build | $O(n)$ | $O(n)$ |
| Heap sort | $O(n \log n)$ | $O(n)$ |


### Time Complexity  
The time complexity of building a heap is $O(n)$<sup>[6]</sup> as proved by the following.

![heap_big_o]

- Inserting an element into a heap is the same as push <sup>[2]</sup>, it involves inserting the element at the next available position in the heap and then reordering the heap to maintain the heap property. The heap property requires that the parent of any node in the heap is either smaller (in the case of a min-heap) or larger (in the case of a max-heap) than its children. The time complexity of inserting an element into a heap is $O(\log n)$, where $n$ is the number of elements in the heap. Each insertion operation requires traversing the height of the heap, which is logarithmic in the number of elements.

- Deleting an element from a heap is the same as pop<sup>[3]</sup>, it involves removing the root node of the heap (which is the smallest element in a min-heap or the largest element in a max-heap) and then reordering the heap to maintain the heap property. It is the same with inserting, and the time complexity is also $O(\log n)$.

- Heap sort is an efficient sorting algorithm that uses a heap to sort an array of elements in $O(n \log n)$ time. Heap sort has the advantage of being an in-place sorting algorithm, meaning that it sorts the array in place without requiring additional memory.


### Space Complexity
The space complexity of a heap is $O(n)$, where n is the number of elements in the heap. This is because a heap is typically implemented using an array, and the array must be large enough to hold all the elements in the heap.


## Implementation

The code implementation can be found in the following files:

[heap.c] -- implementation of functions in C

[heap.h] -- max-heap head filer

[heap.py] -- implementation of the function in Python

[tester.c] -- test script for heapsort and quicksort

[sorts.h] -- header file for quicksort and heapsort

I decided to start developing code in C as I practiced this language throughout this semester and have some familiarity with it. Then I switched to Python and mirrored those functions in C. 


### Language 1: C
When I first implemented building a heap, I thought to create an empty heap instance and then enqueue n elements one by one. In this case the time complexity is $O(n\log n)$ since inserting an element is $O(\log n)$ and repeating n times. However, it is not so effective. During further research, I found that an optimal solution to heapify an existing array only takes $O(n)$ of time complexity. Using a binary tree, it starts with the last non-leaf node of the tree and then moves to its parent. We perform heapify on each node and continue this process until the root of the tree. This bottom-up method is better than the original top-down insertion method regarding time complexity. 


Top-down insertion method 
```c
void build_heap(int arr[], int n) {
    // start with an empty heap and insert elements
    for (int i = 0; i < n; i++) {
        insert_element(arr, i);
    }
}

void insert_element(int arr[], int i) {
    // maintain heap property by swapping with parent
    while (i > 0 && arr[i] > arr[(i-1)/2]) {
        int parent = (i-1) / 2;
        int temp = arr[i];
        arr[i] = arr[parent];
        arr[parent] = temp;
        i = parent;
    }
}

```

Bottom-up heapify method
```c
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
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        max_heapify(a, largest, n);
    } 
}

// converts an array into a heap
void build_max_heap(int a[], int n) {
    for (int i = n / 2; i >= 0; i--) {
        max_heapify(a, i, n);
    } 
}
```

The difference in time complexity comes from each step of heapify. In the bottom-up heapify method, after each step the whole data structure is not guaranteed to be a valid heap; it is a valid heap only after the whole process of heapification is done. In contrast, in the top-down insertion method, after each step (enqueuing an element) the heap is always valid.


### Language 2: Python 
I selected Python not only because it is a widely used language. Besides, the analytics libraries give me the flexibility to experiment with the built-in tools as well as practice quick development. 

Since Python has a built-in library named heapq, I don’t need to implement the fundamental functions to build a heap every time. The heapq library provides several functions for working with heaps, such as heappush(), heappop(), and heappushpop(). 

- heapify(x) -- transform list x into a heap, in-place, in linear time.
- heappush(heap, item) -- push the value item onto the heap, maintaining the heap invariant.
- heappop(heap) -- pop and return the smallest item from the heap, maintaining the heap invariant. If the heap is empty, IndexError is raised. To access the smallest item without popping it, use heap[0].
- heappushpop(heap, item) -- push item on the heap, then pop and return the smallest item from the heap. The combined action runs more efficiently than heappush() followed by a separate call to heappop(). 

```python
import heapq

a = [52, 94, 13, 77, 41]

# build a heap from an array
heapq.heapify(a)

# push an element into the heap
heapq.heappush(a, 10)

# pop the smallest element from the heap
heapq.heappop(a)

# push an element into the heap and pop the smallest element from the heap
heapq.heappushpop(a, 10)
```


## Empirical Analysis
Heapsort is a comparison-based sorting algorithm that uses a heap data structure to sort elements in an array. It consists of two phases: In the first phase, the array to be sorted is converted into a max heap; in the second phase, the largest element (i.e., the one at the tree root) is removed, and a new max heap is created from the remaining elements. The process is repeated until all elements are removed.

![](heapsort.gif)

```c
void heapSort(int a[], int n) {
    // build max heap
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
      max_heapify(a, i, n);
 
    for (i = n - 1; i >= 0; i--) {
        swap(&a[0], &a[i]);
        // Heapify root element to get the highest element at root again
        max_heapify(a, i, 0);
    }
}
```

Heapsort's performance is affected by the heap construction and by the fact that once the array gets bigger than the CPU cache, a lot of cache misses happen. Heapsort does not access continuous memory locations since it often jumps from an index i to $2 * i$ for instance. But the average time complexity can be calculated. Since each call to max_heapify takes $O(\log n)$ because the height of the heap is $O(\log n)$, and then repeated the swap n times. So heapsort takes $O(n\log n)$ overall.

Since both heapsort and quicksort are comparison-based sorting algorithms with similar average-case time complexities of $O(n\log n)$, I will compare their performance and analyze the differences between them.


### Heapsort vs Quicksort
I created tester.c file to test the performance of heapsort and quicksort. I used time_t and clock_gettime() to calculate the time taken to sort the randomly generated array and print out the data in sort_times.csv file.

![q_h_comparison]

As shown in the graph, as the size becomes larger, the time taken by quicksort increases much more slowly than heapsort. It takes heapsort 0.015 seconds to sort an array of about 100,000 elements, while it takes quicksort only about 0.001 seconds. 

The main difference between the two sorting algorithms is in their approach to sorting. Quicksort is a divide-and-conquer algorithm, where the array is divided into smaller sub-arrays and sorted recursively. In each step of the recursion, a pivot element is chosen, and the array is partitioned into two sub-arrays, one containing elements smaller than the pivot and the other containing elements larger than the pivot. The pivot is then placed in its correct position and the two sub-arrays are sorted recursively.

On the other hand, heapsort is based on the heap data structure, which is a complete binary tree that satisfies the Heap property. In heapsort, the array is first transformed into a heap, and then the elements are extracted one by one to obtain the sorted array. This involves repeatedly removing the maximum (or minimum) element from the heap and placing it at the end of the array.

The extra overhead of building the heap structure in heapsort and the fact that quicksort has better cache locality due to its recursive nature, can make quicksort faster in practice. However, heapsort has one special advantage over quicksort. Building the heap is relatively cheap, requiring $O(n)$ time. Removing the maximum-valued record from the heap requires $O(\log n)$ time in the worst case. Thus, if we wish to find the k records with the largest key values in an array, we can do so in time $O(n+k\log n)$. If k is small, this is a substantial improvement over the time required to find the k largest-valued records.


## Application 
The heap data structure is commonly used to implement priority queues, where the highest priority element is always at the top of the heap. The heap allows constant-time access to the highest priority element. So this is an efficient data structure for managing tasks or events that require prioritization<sup>[7]</sup>.

Heapsort can be used in graph algorithms. From the analysis I made in the previous section, one situation where I can take advantage of kth smallest of an array is the implementation of Kruskal’s algorithm for minimal-cost spanning trees. That algorithm requires that edges be visited in ascending order, but this process stops as soon as the minimal spanning tree (MST) is complete. Thus, only a relatively small fraction of the edges need to be sorted.


## Summary
To summarize, both quicksort and heapsort have an average time complexity of $O(n\log n)$, as can be seen from the graphs which follow a $n\log n$ curve. Quicksort performs better than heapsort on random inputs that contain a very small number of repetitions due to better use of caching and fewer swapping operations. 

I learned much about heap data structure and sorting algorithms for calculation with Big O analysis. What I gain most from this project is how to research a data structure topic and formulate a method to analyze it. I reviewed the basic concepts of heapsort and quicksort and learned to use the time_t and clock_gettime() to calculate the time taken to sort the randomly generated array. There are more concrete methods to compare the performance of heapsort and quicksort that I am unable to perform due to the time limit, such as calculating the number of comparisons and swaps separately as the input size gets bigger. 

Overall, this project provided valuable insights into the workings and performance of heap data structure and heapsort algorithms, and demonstrated the importance of careful analysis when choosing between different algorithms for different use cases.



## References
1. Williams, J. W. J. (1964), "Algorithm 232 - Heapsort", Communications of the ACM, 7 (6): 347–348, doi:10.1145/512274.512284. https://dl.acm.org/doi/10.1145/512274.512284 
2. The Python Standard Library, 8.4. heapq — Heap queue algorithm, heapq.heappush. https://docs.python.org/2/library/heapq.html#heapq.heappush
3. The Python Standard Library, 8.4. heapq — Heap queue algorithm, heapq.heappop. https://docs.python.org/2/library/heapq.html#heapq.heappop
4. Hoare, C. A. R. (1961). "Algorithm 64: Quicksort". Comm. ACM. 4 (7): 321. doi:10.1145/366622.366644. https://dl.acm.org/doi/10.1145/366622.366644
5. Wikipedia, "Heap (data structure)," https://en.wikipedia.org/wiki/Heap_(data_structure). Accessed on: Apr 17, 2023. 
6. GeeksforGeeks, "Time Complexity of building a heap", June 17, 2022. https://www.geeksforgeeks.org/time-complexity-of-building-a-heap/
7. GeeksforGeeks, "Applications, Advantages and Disadvantages of Heap", March 6, 2023. https://www.geeksforgeeks.org/applications-advantages-and-disadvantages-of-heap/. Accessed on: Apr 21, 2023.
8. Cormen, Thomas H. "Introduction to Algorithms, 4th Edition". MIT Press, 2022. http://mitpress.mit.edu/9780262046305/introduction-to-algorithms/. Accessed on: Apr 21, 2023.
 
<!-- auto references -->
[heap_type]: heap_type.png
[heap_big_o]: heap_big_o.png
[heapsort.gif]: heapsort.gif
[q_h_comparison]: q_h_comparison.png
[binary_heap]: binary_heap.png