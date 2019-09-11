bool is_biggest(int* nums, int numsSize)
{
       int i; 
        
       for (i = 0; i < numsSize - 1; i++)
               if (nums[i] < nums[i + 1])
                       return false;
        return true;
}
        
void change_to_smallest(int* nums, int numsSize)
{
        int i, k;        
        
        for (i = 0; i < numsSize / 2; i++) {
                k = nums[i];
                nums[i] = nums[numsSize - i - 1];
                nums[numsSize - i - 1] = k;
        }
}

void nextPermutation(int* nums, int numsSize)
{
        int i, j, tmp;
        
        if (is_biggest(nums, numsSize))
                change_to_smallest(nums, numsSize);
        
        if (numsSize == 2) {
                tmp = nums[0];
                nums[0] = nums[1];
                nums[1] = tmp;
        }
        
        for (i = 1; i <= numsSize - 2; i++) {
                for (j = 0; j < i; j++) {
                       if (nums[numsSize - j - 1] > nums[numsSize - i - 1]) {
                              tmp = nums[numsSize - j - 1];
                              nums[numsSize - j - 1] = nums[numsSize - i - 1];
                              nums[numsSize - i - 1] = tmp;
                       }
                }
        }
}
