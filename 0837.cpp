#include <cstdio>

int set[100010], cnt[100010];

int find(int x)
{
    if (set[x] != x) set[x] = find(set[x]);
    return set[x];
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        set[i] = i;
        cnt[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        char op[5];
        scanf("%s", op);
        if (op[0] == 'C') {
            int a, b;
            scanf("%d%d", &a, &b);
            if (find(a) == find(b))
                continue;
            cnt[find(b)] += cnt[find(a)];
            set[find(a)] = find(b);
        } else if (op[1] == '1') {
            int a, b;
            scanf("%d%d", &a, &b);
            if (find(a) == find(b))
                printf("Yes\n");
            else
                printf("No\n");
        } else {
            int a;
            scanf("%d", &a);
            printf("%d\n", cnt[find(a)]);
        }
    }
    return 0;
}
