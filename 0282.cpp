#include <cstdio>
#include <algorithm>

using namespace std;

int s[310];
int f[310][310];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &s[i]);
    }
    for (int i = 1; i <= n; ++i) {
        s[i] += s[i-1];
    }
    for (int len = 2; len <= n; ++len) {
        for (int l = 1; l+len-1 <= n; ++l) {
            int r = l+len-1;
            f[l][r] = f[l][l] + f[l+1][r] + s[r] - s[l-1];
            for (int k = l+1; k <= r-1; ++k) {
                f[l][r] = min(f[l][r], f[l][k] + f[k+1][r] + s[r] - s[l-1]);
            }
        }
    }
    printf("%d", f[1][n]);
    return 0;
}
