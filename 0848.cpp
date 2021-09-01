#include <cstdio>
#include <cstring>

int n, m;
int head[100010], nxt[100010], point[100010], d;
int in[100010];

void insert(int a, int b)
{
    point[d] = b;
    nxt[d] = head[a];
    head[a] = d++;
}

int main()
{
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        insert(a, b);
        in[b]++;
    }
    int queue[100010], front = 0, rear = 0;
    for (int i = 1; i <= n; i++)
        if (!in[i])
            queue[rear++] = i;
    while (front < rear) {
        int t = queue[front++];
        for (int i = head[t]; i != -1; i = nxt[i]) {
            int j = point[i];
            if (!--in[j])
                queue[rear++] = j;
        }
    }
    if (rear != n)
        printf("-1");
    else
        for (int i = 0; i < n; i++)
            printf("%d ", queue[i]);
    return 0;
}
