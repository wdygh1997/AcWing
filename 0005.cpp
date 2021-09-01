#include <cstdio>
#include <algorithm>

using namespace std;

int v[12010], w[12010];
int f[2010];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int vi, wi, si;
        scanf("%d%d%d", &vi, &wi, &si);
        for (int j = 1; j <= si; j *= 2) {
            si -= j;
            v[cnt] = j * vi;
            w[cnt] = j * wi;
            cnt++;
        }
        if (si > 0) {
            v[cnt] = si * vi;
            w[cnt] = si * wi;
            cnt++;
        }
    }
    for (int i = 0; i < cnt; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    printf("%d", f[m]);
    return 0;
}
