#include <cstdio>
#include <algorithm>

using namespace std;

int f[1005][1005];

int main()
{
    int n1, n2;
    scanf("%d%d", &n1, &n2);
    char str1[1005], str2[1005];
    scanf("%s%s", str1+1, str2+1);
    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j) {
            if (str1[i] == str2[j])
                f[i][j] = f[i-1][j-1]+1;
            else
                f[i][j] = max(f[i-1][j], f[i][j-1]);
        }
    }
    printf("%d", f[n1][n2]);
    return 0;
}
