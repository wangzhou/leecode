#include <stdlib.h>
#include <string.h>

int longestOnes(int *A, int ASize, int K)
{
        int max = 0, first = 0, second = 0;
        int tmp = K, i = 0, tmp_max = 0;

        if (!K) {
                for (i = 0; i < ASize; i++) {
                        if (A[i] == 1)
                                tmp_max++;
                        if (i > 0 && (A[i] == 0 || i == ASize - 1 ) && A[i - 1] == 1) {
                                if (tmp_max > max)                
                                        max = tmp_max;
                                tmp_max = 0;
                        }
                }

                return max;
        }

        while (i < ASize && tmp > 0) {
                if (A[i] == 0)
                        tmp--;

                second = i++;  

                if (tmp == 0)
                        while (second + 1 < ASize && A[second + 1] == 1)
                                second++;
        }

        if (second - first + 1 > max)
                max = second - first + 1;               
                
        while (1) {
                /* let's see if we need update second */       
                if (A[first] == 0) {
                        /* update second */
                        if (second == ASize - 1)
                                break;
                        else {
                                second++;
                                while (second + 1 < ASize && A[second + 1] == 1)
                                        second++;
                        }
                }

                if (first + 1 <= second)
                        first++;

                /* update max */
                if (second - first + 1 > max)
                        max = second - first + 1;

                if (second == ASize - 1)
                        break;
        }

        return max;
}
