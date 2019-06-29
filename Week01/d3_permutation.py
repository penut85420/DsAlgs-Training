"""
Author: Penut Chen
Date: 2019-6-29
Description:
  Practice of permutation function.
"""

def main():
    size = 4
    arr = list([a + 1 for a in range(size)])
    count = [0]
    permutation(arr, 0, count)
    print('Total %d' % count[0])

def permutation(arr, idx, count):
    if idx == len(arr):
        print(' '.join([str(x) for x in arr]))
        count[0] += 1
        return 

    i = idx
    while i < len(arr):
        arr[idx], arr[i] = arr[i], arr[idx]
        permutation(arr, idx + 1, count)
        arr[idx], arr[i] = arr[i], arr[idx]
        i += 1
    
if __name__ == "__main__":
    main()