int coinChange(int *coins, int coinsSize, int amount)
{
#define INIT_MAX 1000000
        int *f, *c, ret, i, j, tmp = INIT_MAX;

        f = malloc(sizeof(int) * (amount + 1));
        if (!f)
                return -2;

        f[0] = 0;

        for (i = 1; i <= amount; i++) {
                for (j = 0; j < coinsSize; j++) {
                        if (i - coins[j] >= 0 && f[i - coins[j]] < tmp)
                                tmp = f[i - coins[j]];
                }

                f[i] = tmp + 1;
                tmp = INIT_MAX;
        }

        ret = (f[amount] == INIT_MAX + 1) ? -1 : f[amount];
        free(f);

        return ret;
}
