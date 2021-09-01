#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct edge {
    int a, b, w;
}graph[10010];

int dis[510], bak[510];

int main()
{
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        graph[i] = {x, y, z};
    }
    for (int i = 0; i < k; i++) {
        memcpy(bak, dis, sizeof(bak));
        for (int j = 0; j < m; j ++ ) {
            auto e = graph[j];
            dis[e.b] = min(dis[e.b], bak[e.a] + e.w);
        }
    }

    if (dis[n] > 0x3f3f3f3f / 2)
        printf("impossible");
    else
        printf("%d\n", dis[n]);
    return 0;
}
