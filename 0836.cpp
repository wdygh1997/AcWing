#include <cstdio>

int set[100010];

int find(int x)
{
    if (set[x] != x) set[x] = find(set[x]);
    return set[x];
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++)
        set[i] = i;
    for (int i = 0; i < m; i++) {
        char op[5];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if (op[0]=='M')
            set[find(a)] = find(b);
        else {
            if (find(a)==find(b))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
