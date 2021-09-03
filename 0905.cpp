#include <cstdio>
#include <algorithm>

using namespace std;

struct section {
    int l, r;
    bool operator < (const section &s) const {
        return r < s.r;
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
    int cnt = 0, end = 0xc0c0c0c0;
    for (int i = 0; i < n; ++i) {
        if (end < sec[i].l) {
            cnt++;
            end = sec[i].r;
        }
    }
    printf("%d", cnt);
    return 0;
}
