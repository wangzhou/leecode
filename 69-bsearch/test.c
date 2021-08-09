int mySqrt(int x)
{
    unsigned long i;
    unsigned long y = x;

    for (i = 0; i <= y; i++) {
        if (i * i == y)
            return i;
        if (i * i > y)
            return i - 1;
    }

    return 0;
}

/* 1. int溢出，2. 边界值 */
