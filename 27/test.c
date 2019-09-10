void swap(int *first, int *last)
{
        int k;

        k = *first;
        *first = *last;
        *last = k;
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
                       
                while (last != -1 && *(nums + last) == val)
                        last--;
                
                if (first < last) {
                        swap(first, last);
                        first++;
                        last++;
                        num++;
                }
                       
        } while (first < last);
        
        return numsSize - num;
}
