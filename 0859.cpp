#include <cstdio>
#include <algorithm>

using namespace std;

struct edge {
    int a, b, w;
}graph[200010];

int set[100010];

int find(int x)
{
    if (set[x] != x) set[x] = find(set[x]);
    return set[x];
}

bool cmp(edge e1, edge e2)
{
    return e1.w < e2.w;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        graph[i] = {x, y, z};
    }
    sort(graph, graph+m, cmp);

    for (int i = 0; i < n; i++) set[i] = i;

    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        int x = find(graph[i].a), y = find(graph[i].b);
        if (x != y) {
            set[x] = y;
            res += graph[i].w;
            cnt++;
        }
    }

    if (cnt < n-1)
        printf("impossible");
    else
        printf("%d", res);
    return 0;
}
