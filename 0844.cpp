#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

int g[110][110], d[110][110], n, m;

int bfs()
{
    queue<pair<int, int>> q;
    d[1][1] = 0;
    q.push({1, 1});
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i ++ ) {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (g[x][y] == 0 && d[x][y] == -1) {
                d[x][y] = d[t.first][t.second] + 1;
                q.push({x, y});
            }
        }
    }
    return d[n][m];
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(g, -1, sizeof(g));
    memset(d, -1, sizeof(d));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &g[i][j]);
    int t = bfs();
    printf("%d", t);
    return 0;
}
