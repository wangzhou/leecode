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
        int i, j;

        for (i = 0; i < intervalsSize - 1; i++)
                for (j = 0; j < intervalsSize - 1 - i; j++)
                        if (compare(*(intervals + j), *(intervals + j + 1)) == 1)
                                swap(*(intervals + j), *(intervals + j + 1));
}

bool can_merge(int *a, int *b)
{
       if (a[1] >= b[0])
               return true;
        else
               return false;
}

void do_merge(int *a, int *b)
{
        a[1] = b[1];
}

void update_curr(int *curr, int *b)
{
        curr[0] = b[0];
        curr[1] = b[1];
}

int **__merge(int **intervals, int intervalsSize, int *returnSize)
{
       int merge_num = 0, i, curr = 0;

       for (i =  0; i < intervalsSize - 1; i++) {
              if (can_merge(*(intervals + i), *(intervals + i + 1))) {
                        do_merge(*(intervals + i), *(intervals + i + 1));
                        i++;
                        update_curr(*(intervals + curr), *(intervals + i));
                        curr++;
                        merge_num++;
              }
       }

       *returnSize = *returnSize - merge_num;

       return intervals;
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
