/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **kSmallestPairs(int *nums1, int nums1Size, int *nums2, int nums2Size, int k, int *returnSize, int *returnColumnSizes)
{
        int **ret, i, j, n = 0, curr_1, curr_2;
        
        ret = (int **)malloc(sizeof(int *) * k);  
        if (!ret)
                return NULL;
        
        for (i = 0; i < k; i++) {
                *(ret + i) = (int *)malloc(sizeof(int) * 2);
                if (!*(ret + i))
                        goto err_free_array;
        }
        
        returnColumnSizes = malloc(sizeof(int) * k);
        if (!returnColumnSizes)
               goto err_free_array;
        
        for (n = 0; n < k; n++)
                *(returnColumnSizes + n) = 2;
        
        curr_1 = curr_2 = 0;
        **ret = *nums1;
        *(*ret + 1) = *nums2;              
        n++;
        
        while ((curr_1 < nums1Size) && (curr_2 < nums2Size)) {
                if (*(nums1 + curr_1) + *(nums2 + curr_2 + 1) <
                    *(nums1 + curr_1 + 1) + *(nums2 + curr_2)) {
                        **(ret + n) = *(nums1 + curr_1);
                        *(*(ret + n) + 1) = *(nums2 + curr_2 + 1);              
                        curr_2++;
                } else {
                        **(ret + n) = *(nums1 + curr_1 + 1);
                        *(*(ret + n) + 1) = *(nums2 + curr_2);              
                        curr_1++;
                }             
                n++;
        }
                
        *returnSize = n;
        return ret;
        
err_free_array:
        for (j = 0; j < i; j++)
                free(*(ret + j));
err_free_ret:
        free(ret);
        return NULL;
}
