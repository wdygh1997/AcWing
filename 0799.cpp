#include <cstdio>

int a[100010], c[100010];

int main()
{
    int n, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int r = 0, l = 0; r < n; r++)
    {
        c[a[r]]++;
        while (c[a[r]] > 1)
        {
            c[a[l]]--;
            l++;
        }
        if (r-l+1 > cnt)
            cnt = r-l+1;
    }
    printf("%d", cnt);
    return 0;
}
