#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int head[100010], nxt[200010], point[200010], d;
bool vis[100010];
int ans = 100010;

void insert(int a, int b)
{
    point[d] = b;
    nxt[d] = head[a];
    head[a] = d++;
}

int dfs(int x)
{
    vis[x] = true;
    int num = 0, sum = 0;
    for (int i = head[x]; i != -1; i = nxt[i]) {
        int j = point[i];
        if (vis[j]) continue;
        int son = dfs(j);
        num = max(num, son);
        sum += son;
    }
    num = max(num, n - sum - 1);
    ans = min(ans, num);
    return sum + 1;
}

int main()
{
    scanf("%d", &n);
    memset(head, -1, sizeof(head));
    int a, b;
    for (int i = 0; i < n-1; i++) {
        scanf("%d%d", &a, &b);
        insert(a, b);
        insert(b, a);
    }
    dfs(1);
    printf("%d", ans);
    return 0;
}
