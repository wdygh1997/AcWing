#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    int t;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        int cnt = 0;
        while (t)
        {
            t -= t & -t;
            cnt++;
        }
        printf("%d ", cnt);
    }
    return 0;
}
