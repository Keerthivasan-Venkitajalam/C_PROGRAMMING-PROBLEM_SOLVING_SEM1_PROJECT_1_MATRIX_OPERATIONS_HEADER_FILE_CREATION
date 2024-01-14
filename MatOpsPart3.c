#include "MatOps.h"
#include <stdio.h>

main()
{
    int nA, mA, nB, mB;
    printf("Enter number of rows and columns of matrix A: ");
    scanf("%i%i", &nA, &mA);
    printf("Enter number of rows and columns of matrix B: ");
    scanf("%i%i", &nB, &mB);
    float a[nA][mA], b[nB][mB];
    for (int i = 0; i < nA; i++)
    {
        for (int j = 0; j < mA; j++)
        {
            printf("Element A[%d,%d]: ", i + 1, j + 1);
            scanf("%f", &a[i][j]);
        }
    }
    for (int i = 0; i < nB; i++)
    {
        for (int j = 0; j < mB; j++)
        {
            printf("Element B[%d,%d]: ", i + 1, j + 1);
            scanf("%f", &b[i][j]);
        }
    }
    printf("Matrix Multiplication:\n");
    MatrixMult(&a[0][0], &b[0][0], nA, mA, nB, mB);
}
