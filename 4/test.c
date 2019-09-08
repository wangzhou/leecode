double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int sum_num = nums1Size + nums2Size;
    int curr_index_1 = 0;
    int curr_index_2 = 0;
    /* current min in this array */
    int curr_num;
    int tmp, tmp2;
    int tmp_index;
    int i;
    
    if (!nums1Size || !nums1) {
        if (!nums2Size % 2)
            return (nums3[nums2Size / 2] + nums2[nums2Size / 2 - 1]) / 2;
        else
            return nums2[nums2Size / 2];
    }
    
    if (!nums2Size || !nums2) {
        if (!nums1Size % 2)
            return (nums1[nums1Size / 2] + nums1[nums1Size / 2 - 1]) / 2;
        else
            return nums1[nums1Size / 2];
    }
    
    if (!sum_num % 2) {
        for (i = 0; i < sum_num / 2; i++) {
            if (curr_index_1 = -1) {
                curr_num = 2;
                curr_index_2++;
            } else if (curr_index_2 = -1) {
                curr_num = 1;
                curr_index_1++;
            }
                
            if (nums1[curr_index_1] <= nums2[curr_index_2]) {
                curr_num = 1;
                if (curr_index_1 < nums1Size - 1)
                    curr_index_1++;
                else
                    curr_index_1 = -1;
            } else {
                curr_num = 2;
                if (curr_index_2 < nums2Size - 1)
                    curr_index_2++;
                else
                    curr_index_2 = -1;
            }
        }   
        
        if (curr_num == 1) {
            tmp_index = curr_index_1 - 1;
            tmp = nums1[tmp_index];
        } else {
            tmp_index = curr_index_2 - 1;
            tmp = nums2[tmp_index];       
        }
        
        tmp2 = nums1[curr_index_1] <= nums2[curr_index_2] ? nums1[curr_index_1] : nums2[curr_index_2];
        
        return (tmp + tmp2) / 2;
    } else {
        for (i = 0; i < sum_num / 2 + 1; i++) {
            if (nums1[curr_index_1] <= nums2[curr_index_2]) {
                curr_num = 1;
                curr_index_1++;
            } else {
                curr_num = 2;
                curr_index_2++;
            }
        }
        
        if (curr_num == 1) 
            return nums1[--curr_index_1];
        else
            return nums2[--curr_index_2];
    }
}
