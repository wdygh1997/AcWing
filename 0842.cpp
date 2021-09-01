#include <cstdio>

int path[10], state[10], n;

void dfs(int u)
{
    if (u == n) {
        for (int i = 0; i < n; i++)
            printf("%d ", path[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (state[i] == 0) {
            path[u] = i;
            state[i] = 1;
            dfs(u+1);
            state[i] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    dfs(0);
    return 0;
}
