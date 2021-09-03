#include <cstdio>
#include <algorithm>

using namespace std;

struct section {
    int l, r;
    bool operator < (const section &s) const {
        return l < s.l;
    }
}sec[100010];

int main()
{
    int s, t;
    scanf("%d%d", &s, &t);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &sec[i].l, &sec[i].r);
    }
    sort(sec, sec+n);
    int cnt = 0, i = 0;
    while(i < n) {
        int end = 0xc0c0c0c0;
        while (i < n && sec[i].l <= s) {
            end = sec[i].r > end ? sec[i].r : end;
            i++;
        }
        if (end <= s)
            break;
        else {
            s = end;
            cnt++;
        }
        if (s >= t)
            break;
    }
    if (s >= t)
        printf("%d", cnt);
    else
        printf("-1");
    return 0;
}
