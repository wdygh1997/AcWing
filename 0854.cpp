#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dis[210][210];

int main()
{
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 0; i < 210; i++) dis[i][i] = 0;
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        dis[x][y] = min(dis[x][y], z);
    }
    for (int l = 1; l <= n; l++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][l] + dis[l][j]);
    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (dis[x][y] > 0x3f3f3f3f / 2)
            printf("impossible\n");
        else
            printf("%d\n", dis[x][y]);
    }
    return 0;
}
