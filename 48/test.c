void swap(int *a, int *b)
{
       int tmp;
        
       tmp = *a;
       *a = *b;   
       *b = tmp;
}
void rotate_as_angle(int **matrix, int matrixSize)
{
        int i, j;
        
        for (i = 0; i < matrixSize - 1; i++)
                for (j = i + 1; j <= matrixSize - 1; j++)
                        swap(&matrix[i][j], &matrix[j][i]);
}

void rotate_as_mid(int **matrix, int matrixSize)
{
        int i, j;
        
        for (i = 0; i < matrixSize; i++)
                for (j = 0; j < matrixSize / 2; j++)
                        swap(&matrix[i][j], &matrix[i][matrixSize - 1 - j]);
}

void rotate(int **matrix, int matrixSize, int *matrixColSize)
{
        rotate_as_angle(matrix, matrixSize);
        rotate_as_mid(matrix, matrixSize);
}
