#include "MatOps.h"
#include <stdio.h>

main()
{
    int n, m;
    printf("Enter number of rows and columns: ");
    scanf("%i%i", &n, &m);
    float a[n][m], b[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("Element A[%d,%d]: ", i + 1, j + 1);
            scanf("%f", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("Element B[%d,%d]: ", i + 1, j + 1);
            scanf("%f", &b[i][j]);
        }
    }
    printf("Matrix Sum:\n");
    MatrixSum(&a[0][0], &b[0][0], n, m);
    printf("\n");
    printf("Matrix Difference:\n");
    MatrixDiff(&a[0][0], &b[0][0], n, m);
    printf("\n");
    printf("Matrix Scalar Multiplication by 2:\n");
    MatrixScalarMult(&a[0][0], 2, n, m);
    printf("\n");
    printf("Matrix A Transpose:\n");
    MatrixTranspose(&a[0][0], n, m);
    printf("\n");
    printf("Matrix A Element Sum: %f\n", MatrixElementSum(&a[0][0], n, m));
    printf("\n");
    printf("Matrix A Column Sum:\n");
    MatrixColumnSum(&a[0][0], n, m);
    printf("\n");
    printf("Matrix A Row Sum:\n");
    MatrixRowSum(&a[0][0], n, m);
    printf("\n");
}
