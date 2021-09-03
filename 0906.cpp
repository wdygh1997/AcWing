#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

struct section {
    int l, r;
    bool operator < (const section &s) const {
        return l < s.l;
    }
}sec[100010];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &sec[i].l, &sec[i].r);
    }
    sort(sec, sec+n);
    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < n; ++i) {
        if (heap.empty() || sec[i].l <= heap.top())
            heap.push(sec[i].r);
        else {
            heap.pop();
            heap.push(sec[i].r);
        }
    }
    printf("%d", heap.size());
    return 0;
}
