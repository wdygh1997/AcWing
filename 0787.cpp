#include <cstdio>

using namespace std;

int t[100010];

void MergeSort(int a[], int l, int r)
{
    if (l >= r) return;
    int m = (l+r+1)/2;
    MergeSort(a, l, m-1);
    MergeSort(a, m, r);
    int k = 0, i = l, j = m;
    while (i <= m-1 && j <= r)
        if (a[i] <= a[j]) t[k++] = a[i++];
        else t[k++] = a[j++];
    while (i <= m-1) t[k++] = a[i++];
    while (j <= r) t[k++] = a[j++];
    for (i = l, j = 0; i <= r; i++, j++) a[i] = t[j];
}

int main()
{
    int n, a[100010];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    MergeSort(a, 0, n-1);
    for (int i = 0; i < n-1; i++)
        printf("%d ", a[i]);
    printf("%d", a[n-1]);
    return 0;
}
