#include <stdio.h>
#include <string.h>

#define MAX_LEN 10000
#define MAX_S_LEN (2 * MAX_LEN + 1)

void zFunction2(char *s, int z[]) 
{
    int n = strlen(s);
    z[0] = 0;
    for (int i = 1, l = 0, r = 0; i < n; ++i) 
    {
        if (i <= r)
            z[i] = (r - i + 1 < z[i - l]) ? r - i + 1 : z[i - l];
        else
            z[i] = 0;
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r) 
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

int main(void) {
    char s1[MAX_LEN], s2[MAX_LEN];
    fgets(s1, MAX_LEN, stdin);
    fgets(s2, MAX_LEN, stdin);

    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    if (len1 > 0 && s1[len1 - 1] == '\n') 
    {
        s1[len1 - 1] = '\0';
        len1--;
    }
    if (len2 > 0 && s2[len2 - 1] == '\n') 
    {
        s2[len2 - 1] = '\0';
        len2--;
    }

    char s[MAX_S_LEN];
    int z[MAX_S_LEN] = {0};
    snprintf(s, MAX_S_LEN, "%s#%s", s1, s2);
    int total_len = strlen(s);
    zFunction2(s, z);

    int max_k1 = 0;
    int start_s2 = len1 + 1;
    for (int i = start_s2; i < total_len; ++i) 
    {
        if (i + z[i] == total_len) 
        {
            if (z[i] > max_k1) 
            {
                max_k1 = z[i];
            }
        }
    }

    char s_rev[MAX_S_LEN];
    int z_rev[MAX_S_LEN] = {0};
    snprintf(s_rev, MAX_S_LEN, "%s#%s", s2, s1);
    int total_len_rev = strlen(s_rev);
    zFunction2(s_rev, z_rev);

    int max_k2 = 0;
    int start_s1_in_rev = len2 + 1;
    for (int i = start_s1_in_rev; i < total_len_rev; ++i) 
    {
        if (z_rev[i] == total_len_rev - i) 
        {
            int k = total_len_rev - i;
            if (k > max_k2) 
            {
                max_k2 = k;
            }
        }
    }

    printf("%d %d\n", max_k1, max_k2);
    return 0;
}
