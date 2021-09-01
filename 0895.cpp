#include <cstdio>
#include <algorithm>

using namespace std;

int a[1005], f[1005];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        f[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j])
                f[i] = max(f[i], f[j]+1);
        }
    }
    int res = -1;
    for (int i = 0; i < n; i++) {
        if (f[i] > res)
            res = f[i];
    }
    printf("%d", res);
    return 0;
}
