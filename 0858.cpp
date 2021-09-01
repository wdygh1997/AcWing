#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int graph[510][510];
int dis[510], vis[510];

int main()
{
    memset(graph, 0x3f, sizeof(graph));
    for (int i = 0; i < 510; i++) graph[i][i] = 0;
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        graph[x][y] = graph[y][x] = min(graph[x][y], z);
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    for (int i = 1; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && (t == -1 || dis[j] < dis[t])) t = j;

        vis[t] = 1;
        for (int j = 1; j <= n; j++)
            if (!vis[j]) dis[j] = min(dis[j], graph[t][j]);
    }
    int res = 0, i = 1;
    for (; i <= n; i++) {
        if (dis[i] == 0x3f3f3f3f) {
            printf("impossible");
            break;
        }
        res += dis[i];
    }
    if (i == n+1)
        printf("%d", res);
    return 0;
}
