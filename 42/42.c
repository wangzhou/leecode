int trap(int *height, int heightSize)
{
        int sum = 0, right = 0, left = 0;
        int a, b, c;

        if (heightSize < 3)
                return 0
        a = 0;
        b = 1;
        c = 2;

        if (left == 0 && height[0] <= height[1]) {
                left++;
                while (left < heightSize - 1 && height[left] <= height[left + 1]) {
                        left++;
                }

                if (left == heightSize - 1)
                        return 0;
        } /* find first left point */

        while (tail < heightSize) {
                /* search right point */
                right = left;
                while (height[right] <= height[right + 1])
                        right++;
                right++
                
                if (right == 0 && height[0] > height[1])
                
                /* caculate water */
                /* add sum */
                /* update left one */
        }
}
