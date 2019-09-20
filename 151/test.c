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
        bool is_in_word;
        char *dts, *src;
        dts = src = s;
        int i;

        /* handle only spaces string */
        for (i = 0; i < strlen(s); i++)
                if (*(s + i) != ' ')
                        break;
        if (strlen(s) == i) {
                        *s = '\0';
                        return;
        }

        if (*s == ' ')
                is_in_word = false;
        else
                is_in_word = true;
        
        while (*src != '\0') {
                if (*src != ' ') {
                        *dts = *src;
                        dts++;
                        src++;
                        is_in_word = true;
                } else if (is_in_word) {
                        *dts = ' ';
                        dts++;
                        src++;
                        is_in_word = false;
                } else {
                        src++;
                        is_in_word = false;
                }
                                
        }

        /* remove possible space in tail */
        if (*(dts - 1) == ' ')
                *(dts - 1) = '\0';
        else
                *dts = '\0';
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
                while(*(s + last) != '\0' && *(s + last) != ' ')
                        last++;
                last--;
                string_revert(s + start, s + last);
                
                if (*(s + last + 1) == '\0') {
                        break;
                } else {
                       start = last + 2;
                       last += 2;
                } 
        }
        
        return s;
}
