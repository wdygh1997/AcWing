#include <cstdio>
#include <algorithm>

using namespace std;

int f[1010][1010];

int main()
{
    int m, n;
    char str1[1010], str2[1010];
    scanf("%d%s%d%s", &m, str1+1, &n, str2+1);
    for (int i = 0; i <= m; ++i) {
        f[i][0] = i;
    }
    for (int i = 0; i <= n; ++i) {
        f[0][i] = i;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            f[i][j] = min(f[i-1][j]+1, f[i][j-1]+1);
            if (str1[i] == str2[j])
                f[i][j] = min(f[i][j], f[i-1][j-1]);
            else
                f[i][j] = min(f[i][j], f[i-1][j-1]+1);
        }
    }
    printf("%d", f[m][n]);
    return 0;
}
