#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<pair<int, int>> s;

void merge()
{
    vector<pair<int, int>> r;
    sort(s.begin(), s.end());
    int st = -2e9, ed = -2e9;
    for (auto t : s) {
        if (ed < t.first) {
            if (st != -2e9) r.push_back({st, ed});
            st = t.first, ed = t.second;
        } else ed = max(ed, t.second);
    }
    if (st != -2e9) r.push_back({st, ed});
    s = r;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        s.push_back({l, r});
    }
    merge();
    printf("%d", s.size());
    return 0;
}
