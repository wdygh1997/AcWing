#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int head[100010], nxt[100010], point[100010], d;
int dis[100010];

void insert(int a, int b)
{
    point[d] = b;
    nxt[d] = head[a];
    head[a] = d++;
}

int main()
{
    memset(head, -1, sizeof(head));
    memset(dis, -1, sizeof(dis));
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        insert(a, b);
    }
    queue<int> q;
    dis[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i = head[t]; i != -1; i = nxt[i]) {
            int j = point[i];
            if (dis[j] != -1) continue;
            dis[j] = dis[t]+1;
            q.push(j);
        }
    }

    printf("%d", dis[n]);
    return 0;
}
