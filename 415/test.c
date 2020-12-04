#define BUF_NUM 5102

static void rever_char(char *c1, char *c2)
{
        char tmp;

        tmp = *c2;
        *c2 = *c1;
        *c1 = tmp;
}

static void rever(char *str)
{
        int len;
        int i;

        len  = strlen(str);
        for (i = 0; i < len / 2; i++) {
                rever_char(str + i, str + len - 1 - i);                
        }
}

static int char_2_int(char c)
{
        return c - '0';
}

static char int_2_char(int a)
{
       return a + '0';
}

char *addStrings(char *num1, char *num2)
{
        char *result;
        char *max_num;
        char *min_num;
        int len1;
        int len2;
        int len;
        int min;
        int i;
        int c = 0;
        int sum;

        result = malloc(BUF_NUM);
        if (!result)
                return NULL;

        rever(num1);
        rever(num2);

        len1 = strlen(num1);
        len2 = strlen(num2);
        len = len1 > len2 ? len1 : len2;
        min = len1 < len2 ? len1 : len2;
        max_num = len1 > len2 ? num1 : num2;
        min_num = len1 < len2 ? num1 : num2;

        for (i = 0; i < len; i++) {
                if (i < min) {
                        sum = char_2_int(num1[i]) + char_2_int(num2[i]) + c;
                        result[i] = int_2_char(sum % 10);
                        c = sum / 10;
                } else {
                        sum = 0 + char_2_int(max_num[i]) + c;
                        result[i] = int_2_char(sum % 10);
                        c = sum / 10;
                }

                if ((i == len - 1) && (c != 0))
                        result[i + 1] = int_2_char(c);
        }

        if (c == 0)
                result[i] = '\0';
        else
                result[i + 1] = '\0';

        rever(result);
        return result;
}

