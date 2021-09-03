#include <cstdio>
#include <algorithm>

using namespace std;

struct cow {
    int w, s;
    bool operator < (const cow & c) const {
        return w + s < c.w + c.s;
    }
}all[50010];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &all[i].w, &all[i].s);
    }
    sort(all, all+n);
    int res = 0xc0c0c0c0, sum = 0;
    for (int i = 0; i < n; ++i) {
        res = res > sum - all[i].s ? res : sum - all[i].s;
        sum += all[i].w;
    }
    printf("%d", res);
    return 0;
}
