bool is_biggest(int* nums, int numsSize)
{
       int i; 
        
       for (i = 0; i < numsSize - 1; i++)
               if (nums[i] < nums[i + 1])
                       return false;
        return true;
}

void swap(int *a, int *b)
{
        int tmp;
        
        tmp = *a;
        *a = *b;
        *b = tmp;
}

void revert(int *nums, int first, int last)
{
        int i;
        
        for (i = 0; i < (last - first + 1) / 2; i++)
                swap(nums + first + i, nums + last - i);
}

void change_to_smallest(int* nums, int numsSize)
{
        revert(nums, 0, numsSize - 1);
}

void nextPermutation(int* nums, int numsSize)
{
        int i, j;
        
        if (is_biggest(nums, numsSize)) {
                change_to_smallest(nums, numsSize);
                return;
        }
        
        if (numsSize == 2)
                swap(nums, nums + 1);

        for (i = 1; i <= numsSize - 1; i++) {
                for (j = 0; j < i; j++) {
                       if (nums[numsSize - j - 1] > nums[numsSize - i - 1]) {
                              swap(nums + numsSize - j - 1, nums + numsSize - i - 1);
                              revert(nums, numsSize - i, numsSize - 1);
                              return;
                       }
                }
        }
}
