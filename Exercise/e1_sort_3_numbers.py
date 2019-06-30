"""
Author: Penut Chen
Date: 2019-6-30
Description:
  Try to sort 3 numbers without condition statement.
"""

def main():
    arr = [21, 17, 35]
    print('Before\n  %d %d %d' % tuple(arr))
    arr = sort(arr)
    print('\nAfter\n  %d %d %d' % tuple(arr))


def sort(arr):
    nmax = max(max(arr[0], arr[1]), arr[2])
    nmin = min(min(arr[0], arr[1]), arr[2])
    nmid = sum(arr) - nmax - nmin
    return [nmin, nmid, nmax]
    

if __name__ == "__main__":
    main()