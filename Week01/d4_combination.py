"""
Author: Penut Chen
Date: 2019-6-30
Description:
  Practice of combination function.
"""

def main():
    Combination(['True', 'False'], 5)

class Combination:
    def __init__(self, arr, length):
        self.arr = [str(a) for a in arr]
        self.length = length
        self.copy = list(range(length))
        self.size = len(arr)
        self.count = 0
        self.combination(0)
        print('Total %d' % self.count)
    
    def combination(self, idx):
        if idx == self.length:
            print(' '.join(self.copy))
            self.count += 1
            return
        
        for a in self.arr:
            self.copy[idx] = a
            self.combination(idx + 1)

if __name__ == "__main__":
    main()
