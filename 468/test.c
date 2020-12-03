#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <string.h>

#define IPV4_NUM 4
#define IPV6_NUM 8
#define BUF_NUM 40

char *ipv4 = "IPv4";
char *ipv6 = "IPv6";
char *fail = "Neither";

static int get_num_of_char(char *str, char c)
{
        int num = 0;

        while (*str != '\0') {
                if (*str == c)
                        num++;
                str++;
        }

        return num;
}

static bool is_ipv4(char *ip)
{
        char buf[BUF_NUM];
        char *tmp;
        char *tmp1;
        char *p_buf = buf;
        long val;
        int i = 0;

        if (strlen(ip) > 15)
                return false;
        if (get_num_of_char(ip, '.') != 3)
                return false;

        strncpy(buf, ip, sizeof(buf));
        buf[BUF_NUM - 1] = '\0';

        /* can not do this in strtok, so do it here */
        if (buf[strlen(ip) - 1] == '.')
                return false;

        for (i = 0; i < IPV4_NUM; i++) {
                tmp = strtok(p_buf, ".");
                if (!tmp)
                        return false;
                if (*tmp == '0' && strlen(tmp) > 1)
                        return false;
                tmp1 = tmp;
                while (*tmp1 != '\0') {
                        if (*tmp1 < '0' || *tmp1 > '9')
                                return false;
                        tmp1++;
                }
                val = strtol(tmp, NULL, 0);
                if (val < 0 || val > 255)
                        return false;

                p_buf = NULL;
        }

        tmp = strtok(p_buf, ".");
        if (tmp)
                return false;

        return true;
}

static bool is_ipv6(char *ip)
{
        char buf[BUF_NUM];
        char *tmp;
        char *p_buf = buf;
        int i;
        int num = 0;
        char c;

        strncpy(buf, ip, sizeof(buf));
        buf[BUF_NUM - 1] = '\0';

        if (strlen(ip) > 39)
                return false;
        if (get_num_of_char(ip, ':') != 7)
                return false;

        /* can not do this in strtok, so do it here */
        if (buf[strlen(ip) - 1] == ':')
                return false;

        for (i = 0; i < IPV6_NUM; i++) {
                tmp = strtok(p_buf, ":");
                if (!tmp)
                        return false;
                if (*tmp == '\0')
                        return false;
                while (*tmp != '\0') {
                        c = *tmp;
                        if ((c < '0' || c > '9') &&
                            (c < 'a' || c > 'f') &&
                            (c < 'A' || c > 'F'))
                            return false;
                        tmp++;
                        num++;
                }                
                if (num > 4)
                        return false;
                num = 0;

                p_buf = NULL;
        }
        
        tmp = strtok(p_buf, ":");
        if (tmp)
                return false;

        return true;
}

char *validIPAddress(char *IP)
{
        if (!IP || *IP == '\0')
                return fail;

        if (is_ipv4(IP)) {
                return ipv4;
        } else if (is_ipv6(IP)) {
                return ipv6;
        } else {
                return fail;
        }
}

int main()
{
        char *ip = "172.16.254.1";
        char *ipv6_1 = "2001:0db8:85a3:0:0:8A2E:0370:7334";
        char *ipv6_2 = "2001:0db8:85a3:0:0:8A2E:0370:7334:";
        char *ipv4_w = "1e1.4.5.6";

        printf("result 0: %s\n", validIPAddress(ipv4_w));
        //printf("result 0: %s\n", validIPAddress(ip));
        //printf("result 1: %s\n", validIPAddress(ipv6_1));
        //printf("result 2: %s\n", validIPAddress(ipv6_2));

        while (1);

        return 0;
}