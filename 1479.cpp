#include <cstdio>

int a[10005], f[10005], l[10005];

int main()
{
    int k;
    scanf("%d", &k);
    int flag = 0;
    for (int i = 0; i < k; ++i) {
        scanf("%d", &a[i]);
        if (a[i] >= 0)
            flag = 1;
    }
    if (flag == 0)
        printf("0 %d %d", a[0], a[k-1]);
    else {
        f[0] = a[0];
        l[0] = 0;
        for (int i = 1; i < k; ++i) {
            if (f[i-1]+a[i]>=a[i]) {
                f[i] = f[i-1]+a[i];
                l[i] = l[i-1];
            } else {
                f[i] = a[i];
                l[i] = i;
            }
        }
        int m = 0;
        for (int i = 1; i < k; ++i) {
            if (f[i] > f[m])
                m = i;
        }
        printf("%d %d %d", f[m], a[l[m]], a[m]);
    }
    return 0;
}
