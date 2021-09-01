#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int heap[100010], ph[100010], hp[100010], d = 0;

void swap_heap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(heap[a], heap[b]);
}

void down(int x)
{
    int t = 2*x;
    while (t <= d) {
        if (t+1 <= d && heap[t+1] < heap[t]) t++;
        if (heap[t] < heap[x]) {
            swap_heap(x, t);
            x = t;
            t = 2*x;
        } else break;
    }
}

void up(int x)
{
    while (x/2 >= 1 && heap[x] < heap[x/2]) {
        swap_heap(x, x/2);
        x /= 2;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int m = 0, k, x;
    for (int i = 0; i < n; i++) {
        char op[5];
        scanf("%s", op);
        if (op[0] == 'I') {
            scanf("%d", &x);
            d++;
            m++;
            heap[d] = x;
            ph[m] = d;
            hp[d] = m;
            up(d);
        } else if (op[0] == 'P') {
            printf("%d\n", heap[1]);
        } else if (!strcmp(op, "DM")) {
            swap_heap(1, d);
            d--;
            down(1);
        } else if (op[0] == 'D') {
            scanf("%d", &k);
            k = ph[k];
            swap_heap(k, d);
            d-- ;
            up(k);
            down(k);
        } else if (op[0] == 'C') {
            scanf("%d%d", &k, &x);
            k = ph[k];
            heap[k] = x;
            up(k);
            down(k);
        }
    }
    return 0;
}
