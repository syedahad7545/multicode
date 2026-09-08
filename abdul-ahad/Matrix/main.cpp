#include <iostream>

void swap(int &a, int &b) {
    int c;
    c = a;
    a = b;
    b = c;
}

void show(int **matrix, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

}

int **mult(int **matrix1, int **matrix2, int m1, int n1, int m2, int n2) {
    int **res = new int*[m1];
    for (int i = 0; i < m1; ++i) {
        res[i] = new int[n2];
    }

    for (int i = 0; i < m1; ++i) { // rows traversal
        for (int j = 0; j < n2; ++j) { // The cols of the resultant matrix
            for (int k = 0; k < n1; ++k) { // The cols of the multiplying matrices
                res[i][j] += matrix1[i][k]*matrix2[k][j];
            }
        }
    }
    return res;
}
void transpose(int **matrix, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = i; j < n; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

}

int** add(int **matrix1, int **matrix2, int m , int n) {
    int **res = new int*[m];
    for (int i = 0; i < m; ++i) {
        res[i] = new int[n];
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            res[i][j] += matrix1[i][j] + matrix2[i][j];
        }
    }

    return res;
}
int main() {
    int rows = 3;
    int cols = 3;
    int **matrix1 = new int*[rows];
    int **matrix2 = new int*[rows];

    for (int i = 0; i < rows; ++i) {
        matrix1[i] = new int[cols];
    }
    for (int i = 0; i < rows; ++i) {
        matrix2[i] = new int[cols];
    }


    //matrix init
    for (int i = 0, k = 1; i < rows; ++i) {
        for (int j = 0; j < cols; ++j ,++k) {
            matrix1[i][j] = k;
        }
    }
    for (int i = 0, k = 1; i < rows; ++i) {
        for (int j = 0; j < cols; ++j ,++k) {
            matrix2[i][j] = k;
        }
    }

    int **res = mult(matrix1, matrix2, rows, cols, rows,cols);
    show(res, rows, cols);
    return 0;
}
