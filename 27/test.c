void swap(int *nums, int first, int last)
{
        int k;

        k = *(nums + first);
        *(nums + first) = *(nums + last);
        *(nums + last) = k;
}

int removeElement(int* nums, int numsSize, int val)
{
        int first, last, num = 0;
        
        if (!nums || !numsSize)    
                return 0;
        
        first = 0;
        last = numsSize - 1; 
        
        do {
                while (first != numsSize && *(nums + first) != val)
                        first++;
                       
                while (last != -1 && *(nums + last) == val) {
                        last--;
                        num++;
                }
                
                if (first < last) {
                        swap(nums, first, last);
                        first++;
                        last--;
                        num++;
                }
                       
        } while (first <= last);
