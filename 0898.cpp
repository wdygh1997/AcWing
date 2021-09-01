#include <cstdio>
#include <algorithm>

using namespace std;

int a[505][505], f[505][505];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i  =0; i < n; i++) {
        for (int j = 0; j < i+1; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        f[n-1][i] = a[n - 1][i];
    }
    for (int i = n-2; i >= 0; i--) {
        for (int j = 0; j < i+1; j++) {
            f[i][j] = max(f[i+1][j], f[i+1][j+1]) + a[i][j];
        }
    }
    printf("%d", f[0][0]);
    return 0;
}
