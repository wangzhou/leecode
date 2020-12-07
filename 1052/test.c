#define MAX_MIN 20000

int maxSatisfied(int *customers, int customersSize, int *grumpy, int grumpySize, int X)
{
        int max = 0;
        int first = 0;
        int second;
        int i;
        int j;
        int num;
        int tmp = 0;
        int last;

        if (!customers || !customersSize || !grumpy || !grumpySize || X < 1 || X > MAX_MIN)
                return 0;

        num = customersSize - X + 1;
        second = X - 1;
        for (i = 0; i < num; i++) {
                if (i == 0) {
                        for (j = 0; j < customersSize; j++) {
                                if (j >= first && j <= second) {
                                        max += customers[j];
                                        continue;
                                }
                                if (grumpy[j] == 0)                
                                        max += customers[j];
                        }
                        last = max;
                } else {
                        if (grumpy[second] == 1)
                                tmp += customers[second];
                        if (grumpy[first - 1] == 1)
                                tmp -= customers[first - 1];
                        tmp += last;
                        if (tmp > max)
                                max = tmp;
                        last = tmp;
                        tmp = 0;
                }
                first++;
                second++;
        }

        return max;
}

