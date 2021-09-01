#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<pair<int, int>> o, q;
vector<int> a;
int b[300010], s[300010];

int find(int x)
{
    int l = 0, r = a.size()-1;
    while (l < r)
    {
        int m = (l+r)/2;
        if (a[m] >= x) r = m;
        else l = m+1;
    }
    return l;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int x, c;
        scanf("%d%d", &x, &c);
        o.push_back({x, c});
        a.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        q.push_back({l, r});
        a.push_back(l);
        a.push_back(r);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    for (int i = 0; i < n; i++)
    {
        int x = find(o[i].first)+1;
        b[x] += o[i].second;
    }
    for (int i = 1; i <= a.size(); i++) s[i] = s[i-1] + b[i];
    for (int i = 0; i < m; i++)
    {
        int l = find(q[i].first)+1, r = find(q[i].second)+1;
        printf("%d\n", s[r] - s[l-1]);
    }
    return 0;
}
