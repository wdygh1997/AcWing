#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int graph[510][510], vis[510], dis[510];

int main()
{
    memset(graph, 0x3f, sizeof(graph));
    int n, m;
    scanf("%d%d", &n, &m);
    int x, y, z;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        graph[x][y] = min(graph[x][y], z);
    }

    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;

    for (int i = 0; i < n-1; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && (t == -1 || dis[t] > dis[j])) t = j;

        vis[t] = 1;
        for (int j = 1; j <= n; j ++ )
            dis[j] = min(dis[j], dis[t] + graph[t][j]);
    }

    if (dis[n] == 0x3f3f3f3f)
        printf("-1");
    else
        printf("%d", dis[n]);

    return 0;
}
