#include <cstdio>
#include <cstring>

int head[100010], nxt[200010], point[200010], d;
int color[100010];

void insert(int a, int b)
{
    point[d] = b;
    nxt[d] = head[a];
    head[a] = d++;
}

bool paint(int x, int c)
{
    color[x] = c;
    for (int i = head[x]; i != -1; i = nxt[i]) {
        int y = point[i];
        if (color[y] == -1 && !paint(y, 1 - c) || color[y] == c)
            return false;
    }
    return true;
}

int main()
{
    memset(head, -1, sizeof(head));
    memset(color, -1, sizeof(color));
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        insert(u, v);
        insert(v, u);
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1 && !paint(i, 0)) {
            flag = false;
            break;
        }
    }
    if (flag)
        printf("Yes");
    else
        printf("No");
    return 0;
}
