int searchInsert(int* nums, int numsSize, int target)
{
        int f, l, m;

        if (target <= nums[0])
                return 0;
        if (target == nums[numsSize - 1])
                return numsSize - 1;
        if (target > nums[numsSize - 1])
                return numsSize;

        /* value in f and l will never be target */ 
        f = 0;
        l = numsSize - 1;

        /* f, l will be f + 1 = l, this is the fail search case */
        while (f + 1 < l) {
                m = (f + l) / 2;
                if (nums[m] == target)
                        return m;
                else if (target < nums[m]) {
                        l = m;
                } else {
                        f = m;
                }
        }

        return l;
}

