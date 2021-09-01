#include <cstdio>
#include <cstring>

char g[15][15];
int col[15], md[30], sd[30], n;

void dfs(int r)
{
    if (r == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                printf("%c", g[i][j]);
            printf("\n");
        }
        printf("\n");
        return;
    }
    for (int c = 0; c < n; c++) {
        if (!col[c] && !md[n - r + c] && !sd[r + c]) {
            g[r][c] = 'Q';
            col[c] = md[n - r + c] = sd[r + c] = true;
            dfs(r + 1);
            col[c] = md[n - r + c] = sd[r + c] = false;
            g[r][c] = '.';
        }
    }
}

int main()
{
    scanf("%d", &n);
    memset(g, '.', sizeof(g));
    dfs(0);
    return 0;
}
