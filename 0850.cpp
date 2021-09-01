#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int head[150010], nxt[150010], point[150010], edge[150010], d;
int dis[150010], vis[150010];

void insert(int a, int b, int c)
{
    edge[d] = c;
    point[d] = b;
    nxt[d] = head[a];
    head[a] = d++;
}

int main()
{
    memset(head, -1, sizeof(head));
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap;
    heap.push({0, 1});

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        insert(x, y, z);
    }

    while (!heap.empty()) {
        auto t = heap.top();
        heap.pop();
        int p = t.second;

        if (vis[p]) continue;

        vis[p] = 1;
        for (int i = head[p]; i != -1; i = nxt[i]) {
            int j = point[i];
            if (dis[j] > dis[p] + edge[i]) {
                dis[j] = dis[p] + edge[i];
                heap.push({dis[j], j});
            }
        }
    }

    if (dis[n] == 0x3f3f3f3f)
        printf("-1");
    else
        printf("%d", dis[n]);

    return 0;
}
