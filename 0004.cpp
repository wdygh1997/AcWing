#include <cstdio>
#include <algorithm>

using namespace std;

int v[1010], w[1010], s[1010];
int f[1010];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d%d%d", &v[i], &w[i], &s[i]);

    for (int i = 0; i < n; i++)
        for (int j = m; j >= 0; j--)
            for (int k = 1; k <= s[i] && k * v[i] <= j; k++)
                f[j] = max(f[j], f[j - k * v[i]] + k * w[i]);

    printf("%d", f[m]);
    return 0;
}
