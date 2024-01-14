#include <stdio.h>

void MatrixSum(float *a, float *b, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            float element = *(a + i * cols + j) + *(b + i * cols + j);
            printf("%f ", element);
        }
        printf("\n");
    }
}

void MatrixDiff(float *a, float *b, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            float element = *(a + i * cols + j) - *(b + i * cols + j);
            printf("%f ", element);
        }
        printf("\n");
    }
}

void MatrixScalarMult(float *a, float b, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            float element = *(a + i * cols + j) * b;
            printf("%f ", element);
        }
        printf("\n");
    }
}

void MatrixTranspose(float *a, int rows, int cols)
{
    float b[cols][rows];
    for (int i = 0; i < cols; ++i)
    {
        for (int j = 0; j < rows; ++j)
        {
            b[i][j] = *(a + j * cols + i);
            printf("%f ", b[i][j]);
        }
        printf("\n");
    }
}

float MatrixElementSum(float *a, int rows, int cols)
{
    float sum = 0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            float element = *(a + j * cols + i);
            sum += element;
        }
    }
    return sum;
}

float MatrixRowSum(float *a, int rows, int cols)
{
    float rsumtotal = 0;
    for (int i = 0; i < rows; ++i)
    {
        float rsum = 0;
        for (int j = 0; j < cols; ++j)
        {
            float element = *(a + i * cols + j);
            rsum += element;
        }
        rsumtotal += rsum;
        printf("Row %i Sum: %f\n", i + 1, rsum);
    }
    return rsumtotal;
}

float MatrixColumnSum(float *a, int rows, int cols)
{
    float csumtotal = 0;
    for (int i = 0; i < cols; ++i)
    {
        float csum = 0;
        for (int j = 0; j < rows; ++j)
        {
            float element = *(a + j * cols + i);
            csum += element;
        }
        csumtotal += csum;
        printf("Column %i Sum: %f\n", i + 1, csum);
    }
    return csumtotal;
}

float MatrixDiagonalSum(float *a, int rows, int cols)
{
    if (rows == cols)
    {
        float diagsum = 0;
        for (int i = 0; i < rows; i++)
        {
            diagsum += *(a + cols * i + i);
        }
        return diagsum;
    }
    else
    {
        printf("Matrix is not square.\n");
        return 0;
    }
}

float MatrixAntiDiagonalSum(float *a, int rows, int cols)
{
    if (rows == cols)
    {
        float antidiagsum = 0;
        for (int i = 0; i < rows; i++)
        {
            antidiagsum += *(a + cols * (rows - i - 1) + (i));
        }
        return antidiagsum;
    }
    else
    {
        printf("Matrix is not square.\n");
        return 0;
    }
}

int SymmetryMatrix(float *a, int rows, int cols)
{
    if (rows == cols)
    {
        int count = 0;
        for (int i = 0; i < cols; ++i)
        {
            for (int j = 0; j < rows; ++j)
            {
                float element = *(a + j * cols + i);
                if (element == *(a + i * cols + j))
                {
                    count++;
                }
            }
        }
        if (count == (rows) * (cols))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        printf("Matrix is not square.\n");
        return 0;
    }
}

int OrthogonalityMatrix(float *a, int rows, int cols)
{
    if (rows == cols)
    {
        int onesum = 0, zerosum = 0;
        float b[cols][rows];
        for (int i = 0; i < cols; ++i)
        {
            for (int j = 0; j < rows; ++j)
            {
                b[i][j] = *(a + j * cols + i);
            }
        }
        float c[rows][rows];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int sum = 0;
                for (int k = 0; k < cols; k++)
                {
                    sum += *(a + i * cols + k) * b[k][j];
                }
                c[i][j] = sum;
                if (i == j)
                {
                    if (c[i][j] == 1)
                    {
                        onesum++;
                    }
                }
                if (i != j)
                {
                    if (c[i][j] == 0)
                    {
                        zerosum++;
                    }
                }
            }
        }
        if (onesum == rows && zerosum == rows * (rows - 1))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        printf("Matrix is not square.\n");
        return 0;
    }
}

float MatrixDeterminant(float *a, int rows, int cols)
{
    if (rows == cols)
    {
        float matrix[rows][cols];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                matrix[i][j] = *(a + i * cols + j);
            }
        }
        float det = 1;
        for (int i = 0; i < rows; i++)
        {
            for (int j = i + 1; j < rows; j++)
            {
                float ratio = matrix[j][i] / matrix[i][i];
                for (int k = 0; k < rows; k++)
                {
                    matrix[j][k] = matrix[j][k] - ratio * matrix[i][k];
                }
            }
        }
        for (int i = 0; i < rows; i++)
        {
            det = det * matrix[i][i];
        }
        return det;
    }
    else
    {
        printf("Matrix is not square.\n");
        return 0;
    }
}

int InvertibilityMatrix(float *a, int rows, int cols)
{
    if (rows == cols)
    {
        float matrix[rows][cols];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                matrix[i][j] = *(a + i * cols + j);
            }
        }
        float det = 1;
        for (int i = 0; i < rows; i++)
        {
            for (int j = i + 1; j < rows; j++)
            {
                float ratio = matrix[j][i] / matrix[i][i];
                for (int k = 0; k < rows; k++)
                {
                    matrix[j][k] = matrix[j][k] - ratio * matrix[i][k];
                }
            }
        }
        for (int i = 0; i < rows; i++)
        {
            det = det * matrix[i][i];
        }
        if (det == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        printf("Matrix is not square.\n");
        return 0;
    }
}

void MatrixMult(float *a, float *b, int rowsA, int colsA, int rowsB, int colsB)
{
    if (colsA == rowsB)
    {
        for (int i = 0; i < rowsA; i++)
        {
            for (int j = 0; j < colsB; j++)
            {
                float sum = 0;
                for (int k = 0; k < rowsB; k++)
                {
                    sum += *(a + i * colsA + k) * *(b + k * colsB + j);
                }
                printf("%f ", sum);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Matrix Multiplication not possible, invalid dimensions.\n");
    }
}