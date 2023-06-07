from ast import main
import heapq
 
# python file to demonstrate the use of heap data structure
def main():
    a = [52, 94, 13, 77, 41]

    # build a heap from a list
    heapq.heapify(a)

    # push an element into the heap
    heapq.heappush(a, 10)

    # pop the smallest element from the heap
    heapq.heappop(a)

    # push an element into the heap and pop the smallest element from the heap
    heapq.heappushpop(a, 10)

    def heap_sort(arr):
        # Convert the list to a heap in-place
        heapq.heapify(arr)
    
        # Create an empty result list
        result = []
    
        # Pop items from the heap and add them to the result list
        while arr:
            result.append(heapq.heappop(arr))
        
        # Return the sorted list
        return result

 
if __name__ == '__main__':
    main()