#include <stdio.h>

// Define a structure to hold the 2x2 matrix
typedef struct {
    int data[2][2];
} Matrix2x2;

Matrix2x2 MultiplyMatricesV2(const Matrix2x2 a, const Matrix2x2 b) {
    Matrix2x2 c; // Create a local struct

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            c.data[i][j] = 0;
            for (int k = 0; k < 2; ++k) {
                c.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return c; // The entire struct is copied out of the function
}


void MultiplyMatrices(int a[2][2], int b[2][2], int c[2][2]) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            c[i][j] = 0;
            for (int k = 0; k < 2; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main(void) {
    int a[2][2] = {{1, 2}, {3, 4}};
    int b[2][2] = {{5, 6}, {7, 8}};
    int c[2][2];

    Matrix2x2 matA = {{{1, 2}, {3, 4}}};
    Matrix2x2 matB = {{{5, 6}, {7, 8}}};
    Matrix2x2 matC = MultiplyMatricesV2(matA, matB);

    // MultiplyMatrices(a, b, c);

    // for (int i = 0; i < 2; ++i) {
    //     for (int j = 0; j < 2; ++j) {
    //         printf("%d%c", c[i][j], (j == 1) ? '\n' : ' ');
    //     }
    // }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%d%c", matC.data[i][j], (j == 1) ? '\n' : ' ');
        }
    }

    return 0;
}