int search(int* nums, int numsSize, int target)
{
        int f, l, m;

        if (!nums || numsSize < 1 || numsSize > 10000)
                return -1;
        if (target < nums[0] || target > nums[numsSize - 1])
                return -1;
        if (nums[0] == target)
                return 0;
        if (nums[numsSize - 1] == target)
                return numsSize - 1;

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

        return -1;
}
