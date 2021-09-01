#include <cstdio>

int a[100010], b[100010];

int main()
{
    int n, m, x;
    scanf("%d%d%d", &n, &m, &x);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    for (int i = 0, j = m-1; i < n; i++) {
        while (j >= 0 && a[i] + b[j] > x)
            j--;
        if (j >= 0 && a[i] + b[j] == x)
            printf("%d %d", i, j);
        if (j < 0)
            break;
    }
    return 0;
}
