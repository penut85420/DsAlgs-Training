"""
Author: Penut Chen
Date: 2019-7-1
Description:
  Practice of matrix multiplication.
"""

import random

def main():
    a = Matrix(size=(3, 2), name='Matrix A')
    b = Matrix(size=(2, 4), name='Matrix B')

    print(a, end='\n\n')
    print(b, end='\n\n')
    print(a * b)

class Matrix:
    def __init__(self, matrix=None, size=None, name='matrix'):
        self.size = size
        self.row, self.col = size
        self.name = name
        if matrix is None:
            self.matrix = [[random.randint(0, 9) for i in range(self.col)] for j in range(self.row)]
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

    def __mul__(self, another):
        row_a, col_a = self.size
        row_b, col_b = another.size
        m = [[sum([self.matrix[i][k] * another.matrix[k][j] for k in range(col_a)]) for j in range(col_b)] for i in range(row_a)]
        return Matrix(matrix=m, size=(row_a, col_b), name='%s x %s' % (self.name, another.name))


if __name__ == "__main__":
    main()