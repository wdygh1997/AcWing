#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int head[100010], nxt[100010], point[100010], edge[100010], d;
int dis[100010], vis[100010];

void insert(int x, int y, int z)
{
    edge[d] = z;
    point[d] = y;
    nxt[d] = head[x];
    head[x] = d++;
}

int main()
{
    memset(head, -1, sizeof(head));
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        insert(x, y, z);
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    queue<int> q;
    q.push(1);
    vis[1] = 1;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        vis[t] = 0;

        for (int i = head[t]; i != -1; i = nxt[i]) {
            int j = point[i];
            if (dis[j] > dis[t] + edge[i]) {
                dis[j] = dis[t] + edge[i];
                if (!vis[j]) {
                    q.push(j);
                    vis[j] = 1;
                }
            }
        }
    }

    if (dis[n] == 0x3f3f3f3f)
        printf("impossible");
    else
        printf("%d", dis[n]);
    return 0;
}
