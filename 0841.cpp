#include <cstdio>

unsigned long long hash[100010], base[100010];

unsigned long long get(int l, int r)
{
    return hash[r] - hash[l-1] * base[r-l+1];
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    char str[100010];
    scanf("%s", str+1);
    base[0] = 1;
    for (int i = 1; i <= n; i++) {
        hash[i] = hash[i-1]*131 + str[i];
        base[i] = base[i-1]*131;
    }
    for (int i = 0; i < m; i++) {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if (get(l1, r1) == get(l2, r2)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
