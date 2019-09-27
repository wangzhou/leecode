/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **kSmallestPairs(int *nums1, int nums1Size, int *nums2, int nums2Size, int k, int *returnSize, int **returnColumnSizes)
{
        int **ret, **ret_n, i, j, l, n = 0, curr_1, curr_2;
        
        if (!nums1Size || !nums2Size) {
                *returnSize = 0;
                *returnColumnSizes = NULL;
                return NULL;
        }
        
        /* pre-allocate reture array */
        ret = malloc(sizeof(int *) * k);  
        if (!ret)
                return NULL;
        
        for (i = 0; i < k; i++) {
                *(ret + i) = malloc(sizeof(int) * 2);
                if (!*(ret + i))
                        goto err_free_array;
        }
        
        curr_1 = curr_2 = 0;
        **ret = *nums1;
        *(*ret + 1) = *nums2;              
        printf("%d: %d, %d\n", n, **(ret + n), *(*(ret + n) + 1));
        n++;
        
        while (n < k && (curr_1 < nums1Size) && (curr_2 < nums2Size)) {
                if ((*(nums1 + curr_1) + *(nums2 + curr_2 + 1)) <=
                    (*(nums1 + curr_1 + 1) + *(nums2 + curr_2))) {
                        **(ret + n) = *(nums1 + curr_1);
                        *(*(ret + n) + 1) = *(nums2 + curr_2 + 1);              
                        curr_2++;
                } else {
                        **(ret + n) = *(nums1 + curr_1 + 1);
                        *(*(ret + n) + 1) = *(nums2 + curr_2);              
                        curr_1++;
                }             
                printf("%d: %d, %d\n", n, **(ret + n), *(*(ret + n) + 1));
                n++;
        }
        
        *returnColumnSizes = malloc(sizeof(int) * n);
        if (!*returnColumnSizes)
                goto err_free_array;
        
        for (l = 0; l < n; l++)
                *(*returnColumnSizes + l) = 2;
                
        *returnSize = n;
        
        if (n == k) {
                return ret;
        } else {
                ret_n = malloc(sizeof(int *) * n);  
                if (!ret_n)
                        return NULL;
        
                for (i = 0; i < n; i++) {
                        *(ret_n + i) = malloc(sizeof(int) * 2);
                        if (!*(ret_n + i))
                                goto err_free_array;
                        **(ret_n + i) = **(ret + i);
                        *(*(ret_n + i) + 1) = *(*(ret + i) + 1);
                }               
                
                for (j = 0; j < k; j++)
                        free(*(ret + j));
                free(ret);
                
                return ret_n;
        }
        
err_free_array:
        for (j = 0; j < i; j++)
                free(*(ret + j));
err_free_ret:
        free(ret);
        return NULL;
}