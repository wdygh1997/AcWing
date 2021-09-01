#include <cstdio>

int a[100010], b[100010];

void insert(int l, int r, int c)
{
    b[l] += c;
    b[r+1] -= c;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int t;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        insert(i, i, a[i]);
    int l, r, c;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }
    for (int i = 1; i <= n; i++)
        b[i] += b[i-1];
    printf("%d", b[1]);
    for (int i = 2; i <= n; i++)
        printf(" %d", b[i]);
    return 0;
}
