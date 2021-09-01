#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int n, m;

int head[2010], nxt[10010], point[10010], edge[10010], d;
int dis[2010], vis[2010], cnt[2010];

void insert(int x, int y, int z)
{
    edge[d] = z;
    point[d] = y;
    nxt[d] = head[x];
    head[x] = d++;
}

bool spfa()
{
    queue<int> q;
    for (int i = 1; i <= n; i ++ ) {
        q.push(i);
        vis[i] = 1;
    }

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        vis[t] = 0;

        for (int i = head[t]; i != -1; i = nxt[i]) {
            int j = point[i];
            if (dis[j] > dis[t] + edge[i]) {
                dis[j] = dis[t] + edge[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return true;
                if (!vis[j]) {
                    q.push(j);
                    vis[j] = 1;
                }
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof(head));

    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        insert(x, y, z);
    }

    if (spfa()) printf("Yes");
    else printf("No");

    return 0;
}
