/* flag 0: a b a, flag 1: a b b a */
char *find_pstr(char *mid, int i, int *length, int s_len, int flag)
{
       int max, first, last, len;
        
       if (flag == 0) {
               max = 1;
               first = i - 1;
               last = i + 1;
               while (first >= 0 && last <= s_len - 1) {
                        if (*(mid - max) != *(mid + max))
                                break;
                        max++;       
                        first--;
                        last++;
               }
               len = (max - 1) * 2 + 1;
       } else if (flag == 1) {
               max = 0;
               first = i;
               last = i + 1;
               while (first >= 0 && last <= s_len - 1) {
                        if (*(mid - max) != *(mid + max + 1))
                                break;
                        max++;       
                        first--;
                        last++;
               }
               len = max * 2;
       } else {
               return NULL;
       }
        
       *length = len;
       return mid - max + 1; 
}

char *longestPalindrome(char *s)
{
        int i, length, sub_len, max = 1;
        char *ret, *tmp, *curr;
        
        if (!s || !(length = strlen(s)))
                return s;
        
        for (i = 0; i < length; i++) {
                curr = find_pstr(s + i, i, &sub_len, length, 0);
                if (sub_len >= max) {
                       max = sub_len; 
                       tmp = curr;
                }
                
                if (i != length - 1) {
                        curr = find_pstr(s + i, i, &sub_len, length, 1);
                        if (sub_len >= max) {
                                max = sub_len; 
                                tmp = curr;
                        }
                }
        }
        
        ret = (char *)malloc(max + 1);
        if (!ret)
                return NULL;
        
        strncpy(ret, tmp, max); 
        *(ret + max) = '\0';
        
        return ret; 
}
