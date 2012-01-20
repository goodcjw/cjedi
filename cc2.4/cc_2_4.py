#! /usr/bin/env python

def rotateMatrix(matrix):
    n = len(matrix)
    for i in range(0, n/2):
        for j in range(0, n - 1 - 2*i):
            k = i+j
            tmp = matrix[i][k]
            matrix[i][k] = matrix[n-1-k][i]
            matrix[n-1-k][i] = matrix[n-1-i][n-1-k]
            matrix[n-1-i][n-1-k] = matrix[k][n-1-i]
            matrix[k][n-1-i] = tmp

def printMatrix(matrix):
    n = len(matrix)
    if n == 0:
        return
    m = len(matrix[0])
    outstr = ''
    for i in range(0, n):
        for j in range(0, m):
            outstr += ('%d ' % matrix[i][j])
        outstr += '\n'
    print outstr

def main():
    m1 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    m2 = [[1, 2, 3, 4],
          [5, 6, 7, 8],
          [9, 0, 1, 2],
          [3, 4, 5, 6]]
    printMatrix(m2)
    rotateMatrix(m2)
    printMatrix(m2)

if __name__ == '__main__':
    main()
