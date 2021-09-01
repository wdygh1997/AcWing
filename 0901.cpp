#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int mtx[310][310], f[310][310];
int dx[4]={-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

int dp(int i, int j)
{
    if (f[i][j] != -1)
        return f[i][j];
    f[i][j] = 1;
    for (int k = 0; k < 4; ++k) {
        int a = i+dx[k], b = j+dy[k];
        if (mtx[a][b] != -1 && mtx[a][b] < mtx[i][j])
            f[i][j] = max(f[i][j], dp(a, b)+1);
    }
    return f[i][j];
}

int main()
{
    int r, c;
    scanf("%d%d", &r, &c);
    memset(mtx, -1, sizeof(mtx));
    memset(f, -1, sizeof(f));
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            scanf("%d", &mtx[i][j]);
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            dp(i, j);
    int res = 0;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            res = max(res, f[i][j]);
    printf("%d", res);
    return 0;
}
