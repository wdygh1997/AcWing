#include <cstdio>
#include <algorithm>

using namespace std;

int v[110][110], w[110][110], s[110];
int f[110];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
        for (int j = 0; j < s[i]; j++)
            scanf("%d%d", &v[i][j], &w[i][j]);
    }
    for (int i = 0; i < n; i++)
        for (int j = m; j >= 0; j--)
            for (int k = 0; k < s[i]; k++)
                if (v[i][k] <= j)
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);

    printf("%d", f[m]);
    return 0;
}
