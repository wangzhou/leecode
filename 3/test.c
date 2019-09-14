/* has repeating return true, caller should make end > s */
bool has_repeating_c(char *s, char *end)
{
       char *curr;

       if (s + 1 == end) {
               if (*s == *end)
                       return true;
               else
                       return false;
       }

       if (end > s && has_repeating_c(s + 1, end)) {
               return true;
       } else {
               curr = s + 1;
               while (curr <= end) {
                       if (*s == *curr)
                               return true;
                       curr++;
               }
               return false;
       }
}

int lengthOfLongestSubstring(char *s)
{
        int s_length, max = 1, i, j = 1;

        if (!s || !strlen(s))
                return 0;

        s_length = strlen(s);
        for (i = 0; i < s_length; i++) {
               /* if current max is bigger then remain string, return directly */
               if (max >= s_length - i)
                       return max;

               for (; j < s_length; j++) {
                       if (has_repeating_c(s + i, s + j))
                               break;
                       else if (j - i + 1 > max)
                               max = j - i + 1;
               }
        }

        return max;
}
