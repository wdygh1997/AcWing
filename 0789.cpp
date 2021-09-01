#include <cstdio>

int a[100010], k;

int BinarySearch_1(int l, int r)
{
    while (l < r)
    {
        int m = (l+r)/2;
        if (a[m]>=k) r = m;
        else l = m+1;
    }
    return l;
}

int BinarySearch_2(int l, int r)
{
    while (l < r)
    {
        int m = (l+r+1)/2;
        if (a[m]<=k) l = m;
        else r = m-1;
    }
    return l;
}

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i=0; i<n; i++)
        scanf("%d", &a[i]);
    for (int i=0; i<q; i++)
    {
        scanf("%d", &k);
        int begin = BinarySearch_1(0, n-1), end = BinarySearch_2(0, n-1);
        if (a[begin] != k)
            printf("-1 -1\n");
        else
            printf("%d %d\n", BinarySearch_1(0, n-1), BinarySearch_2(0, n-1));
    }
    return 0;
}
