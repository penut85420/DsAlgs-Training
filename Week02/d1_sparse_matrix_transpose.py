import random

def main():
    a = SparseMatrix(30, 50, rand=True)
    print(a, end='\n\n')
    a.transpose()
    print(a)

class SparseMatrix:
    def __init__(self, row, col, rand=False):
        self.row = row
        self.col = col
        self.terms = list()
        if rand:
            self._random_generate()
    
    def _random_generate(self):
        size = self.row * self.col
        n = size // random.randint(3, 5)
        
        m = [(i // self.col, i % self.col, random.randint(10, 99)) for i in range(size)]
        
        for i in range(n):
            r = random.randint(0, size - 1)
            t = m[r]
            m[r] = m[i]
            m[i] = t

        self.terms = sorted(m[:n])
        self.size = len(self.terms)

    def __str__(self):
        r = ['=== %dx%d Total %d ===' % (self.row, self.col, len(self.terms))]
        for term in self.terms:
            r.append('(%d, %d, %d)' % term)
        r.append('')
        
        idx = 0
        for i in range(self.row):
            col_str = []
            for j in range(self.col):
                val = 0
                if idx < self.size:
                    if i == self.terms[idx][0] and j == self.terms[idx][1]:
                        val = self.terms[idx][2]
                        idx += 1
                col_str.append('%2d' % val)
            r.append(' '.join(col_str))
        
        return '\n'.join(r)

    def transpose(self):
        terms = list()
        for term in self.terms:
            terms.append((term[1], term[0], term[2]))
        self.row, self.col = self.col, self.row
        self.terms = sorted(terms)

if __name__ == "__main__":
    main()