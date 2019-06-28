"""
Author: Penut Chen
Date: 2019-6-28
Description:
  Practice of selection sort algorithm.
"""
import random
import time


def main():
    arr = shuffle_array(25)
    
    print('Before sort')
    display_array(arr)

    selection_sort(arr)
    
    print('\nAfter sort')
    display_array(arr)


def measure(run_times, size):
    print('\nRun %d Times - Array Size: %d\n' % (run_times, size))
    cost_record = list()
    for i in range(run_times):
        arr = shuffle_array(size)
        begin = time.clock()
        selection_sort(arr)
        cost = time.clock() - begin
        cost_record.append(cost)
        print('Run %2d Time Cost: %.6f' % (i + 1, cost))
    
    avg_cost = sum(cost_record) / run_times
    print('\nAverage Time Cost: %.6f' % avg_cost)

def shuffle_array(n):
    arr = list(range(n))
    random.shuffle(arr)
         
    return arr


def display_array(arr):
    print(' '.join([str(a) for a in arr]))


def selection_sort(arr, reverse=False):
    n = len(arr)
    
    i = 0
    while i < n:
        j = 0
        m = 0
        while j < n - i:
            if reverse and arr[m] > arr[j]:
                m = j
            if not reverse and arr[m] < arr[j]:
                m = j
            j += 1
        arr[m], arr[j-1] = arr[j-1], arr[m]
        i += 1


if __name__ == "__main__":
    main()
    measure(25, 5000)