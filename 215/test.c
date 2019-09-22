void swap(int *a, int *b)
{
        int tmp;

        tmp = *a;
        *a = *b;
        *b = tmp;
}

int findKthLargest(int *nums, int numsSize, int k)
{
        int i, j;
        
        for (i = 0; i < numsSize - 1; i++)
               for (j = 0; j < numsSize - 1 - i; j++)
                        if (*(nums + j) > *(nums + j + 1))                       
                                swap(nums + j, nums + j + 1);
       
        return nums[numsSize - k];
}
