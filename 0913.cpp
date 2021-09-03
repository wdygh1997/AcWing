#include <cstdio>
#include <algorithm>

using namespace std;

int arr[100010];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n);
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        res += arr[i] * (n-1-i);
    }
    printf("%lld", res);
    return 0;
}
