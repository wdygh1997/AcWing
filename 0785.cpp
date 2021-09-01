#include <cstdio>
#include <algorithm>

using namespace std;

void QuickSort(int a[], int l, int r)
{
    if (l >= r) return;
    int i = l-1, j = r+1, x = a[(l+r)/2];
    while (i < j)
    {
        do i++; while (a[i] < x);
        do j--; while (a[j] > x);
        if (i < j) swap(a[i], a[j]);
    }
    QuickSort(a, l, j);
    QuickSort(a, j+1, r);
}

int main()
{
    int n, a[100010];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    QuickSort(a, 0, n-1);
    for (int i = 0; i < n-1; i++)
        printf("%d ", a[i]);
    printf("%d", a[n-1]);
    return 0;
}
