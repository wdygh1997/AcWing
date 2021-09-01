#include <cstdio>
#include <algorithm>

using namespace std;

int heap[100010], d = 0;

void down(int x)
{
    int t = 2*x;
    while (t <= d) {
        if (t+1 <= d && heap[t+1] < heap[t]) t++;
        if (heap[t] < heap[x]) {
            swap(heap[x], heap[t]);
            x = t;
            t = 2*x;
        } else break;
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &heap[i]);
    d = n;
    for (int i = n/2; i > 0; i--) down(i);
    for (int i = 0; i < m; i++) {
        printf("%d ", heap[1]);
        heap[1] = heap[d];
        d--;
        down(1);
    }
    return 0;
}
