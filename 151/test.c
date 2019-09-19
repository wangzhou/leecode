void string_revert(char *start, char *last)
{
        char tmp;
        
        while (start != last && start != last + 1) {
               tmp = *start;
               *start = *last;
               *last = tmp;
                
               start++;
               last--;
        }
}

/* remove no need space */
void string_compact(char *s)
{
        char *dts, *src;
        dts = src = s;
        bool is_write_space = false;
        
        while (*src != '\0') {
                if (*src != ' ' && dts < src) {
                        *dts = *src;
                        dts++;
                        src++;
                }
                                
        }
}

char *reverseWords(char *s)
{
        int len, start, last;

        if (!s || !strlen(s))
                return s;
        
        string_compact(s);
        
        if (!(len = strlen(s)))
                return s;
        
        string_revert(s, s + len - 1);
        
        start = last = 0;
        while ((s + start) != '\0') {
                while((s + last) != '\0' && (s + last) != ' ')
                        last++;
                last--;
                string_revert(s + start, s + last);
                
                if ((s + last + 1) == '\0') {
                        break;
                } else {
                       start = last + 2;
                       last += 2;
                } 
        }
        
        return s;
}
