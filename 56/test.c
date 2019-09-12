/*
 * define [1, 3] < [5, 6], if can be merged, define they are equal
 * 
 * define < return -1, = return 0, > return 1
 */
int compare(int *a, int *b)
{
       if (a[1] < b[0]) 
               return -1;
       if (a[0] > b[1])
               return 1;
        
        return 0;
}

void swap(int *a, int *b)
{
        int tmp;
        
        tmp = a[0];
        a[0] = b[0];
        b[0] = tmp;
        
        tmp = a[1];
        a[1] = b[1];
        b[1] = tmp;
}

void sort(int **intervals, int intervalsSize,
          int (*compare)(int *a, int *b), void (*swap)(int *a, int *b))
{
}

int **__merge(int **intervals, int intervalsSize, int *returnSize)
{
       return NULL; 
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **merge(int **intervals, int intervalsSize, int *intervalsColSize,
            int *returnSize, int **returnColumnSizes)
{
        sort(intervals, intervalsSize, compare, swap);
        
        return __merge(intervals, intervalsSize, returnSize);
}