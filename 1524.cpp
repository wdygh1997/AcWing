#include <cstdio>
#include <cstring>

char str[1010];
int f[1010][1010];

int main()
{
    fgets(str, 1010, stdin);
    int res = 1;
    memset(f, 0, sizeof(f));
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        f[i][i] = 1;
        if (i < len-1) {
            if (str[i] == str[i+1]) {
                f[i][i+1] = 1;
                res = 2;
            }
        }
    }
    for (int l = 3; l <= len; ++l) {
        for (int i = 0; i + l -1 < len; ++i) {
            int j = i+l-1;
            if (str[i] == str[j] && f[i+1][j-1] == 1) {
                f[i][j] = 1;
                res = l;
            }
        }
    }
    printf("%d\n", res);
    return 0;
}
