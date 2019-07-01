"""
Author: Penut Chen
Date: 2019-7-1
Description:
  Practice of matrix transpose.
"""

import random

def main():
    a = Matrix(size=(3, 5), name='Matrix A')

    print(a, end='\n\n')
    print(a.transpose())

class Matrix:
    def __init__(self, matrix=None, size=None, name='matrix'):
        self.size = size
        self.row, self.col = size
        self.name = name
        if matrix is None:
            self.matrix = [[random.randint(10, 99) for i in range(self.col)] for j in range(self.row)]
        else:
            self.matrix = [[j for j in i] for i in matrix]

    def __str__(self):
        m = '\n'.join([' '.join(['%3d' % x for x in row]) for row in self.matrix])
        return '%s\n%s' % (self.name, m)

    def __add__(self, another):
        row, col = self.row, self.col
        m = [[self.matrix[i][j] + another.matrix[i][j] for j in range(col)] for i in range(row)]
        return Matrix(matrix=m, size=self.size, name='%s + %s' % (self.name, another.name))
    
    def transpose(self):
        row, col = self.col, self.row
        m = [[self.matrix[j][i] for j in range(col)] for i in range(row)]
        return Matrix(matrix=m, size=(row, col), name='Transpose of %s' % self.name)

if __name__ == "__main__":
    main()