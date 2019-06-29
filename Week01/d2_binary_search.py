"""
Author: Penut Chen
Date: 2019-6-29
Description:
  Practice of binary search algorithm.
"""

def main():
    size = 10
    arr = [x * 2 + 1 for x in range(size)]
    
    for i in range(size * 2 + 1):
        print('\nSearching %d' % i)
        idx = binary_search(arr, 0, size, i)
        print('Found target at index %d' % idx)


def binary_search(arr, left, right, target):
    middle = (left + right) // 2

    print('[%d, %d] Looking at index %d' % (left, right, middle))

    if arr[middle] == target:
        return middle
    
    if left >= right - 1:
        return -1

    if arr[middle] < target:
        left = middle
    
    if arr[middle] > target:
        right = middle

    return binary_search(arr, left, right, target)

if __name__ == "__main__":
    main()