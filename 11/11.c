int maxArea(int *height, int heightSize)
{
        int max = 0, tmp, head = 0, tail = heightSize - 1;

        while (head < tail) {
                tmp = (height[head] < height[tail] ? height[head] : height[tail]) * (tail - head);
                if (tmp > max)
                       max = tmp; 

                if (height[head] < height[tail])
                        head++;
                else
                        tail--;
        }

        return max;
}
