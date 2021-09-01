#include <cstdio>
#include <cstring>

int head[1010], nxt[100010], point[100010], d;
int vis[1010], match[1010];

void insert(int a, int b)
{
    point[d] = b;
    nxt[d] = head[a];
    head[a] = d++;
}

bool find(int x)
{
    for (int i = head[x]; i != -1; i = nxt[i]) {
        int y = point[i];
        if (!vis[y]) {
            vis[y] = 1;
            if (!match[y] || find(match[y])) {
                match[y] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    memset(head, -1, sizeof(head));
    int n1, n2, m;
    scanf("%d%d%d", &n1, &n2, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        insert(a, b);
    }
    int cnt = 0;
    for (int i = 1; i <= n1; i ++ ) {
        memset(vis, 0, sizeof(vis));
        if (find(i)) cnt++;
    }
    printf("%d", cnt);
    return 0;
}
