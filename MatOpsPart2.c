#include "MatOps.h"
#include <stdio.h>

main()
{
    int n;
    printf("Enter number of rows/columns: ");
    scanf("%i", &n);
    float a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Element A[%d,%d]: ", i + 1, j + 1);
            scanf("%f", &a[i][j]);
        }
    }
    printf("Matrix Diagonal Sum: %f\n", MatrixDiagonalSum(&a[0][0], n, n));
    printf("Matrix Anti Diagonal Sum: %f\n", MatrixAntiDiagonalSum(&a[0][0], n, n));
    printf("Invertibility: %i\n", InvertibilityMatrix(&a[0][0], n, n));
    printf("Symmetry: %i\n", SymmetryMatrix(&a[0][0], n, n));
    printf("Orthogonality: %i\n", OrthogonalityMatrix(&a[0][0], n, n));
    printf("Matrix Determinant: %f\n", MatrixDeterminant(&a[0][0], n, n));
}
