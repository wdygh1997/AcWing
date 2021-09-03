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
    int t = n/2, res = 0;
    for (int i = 0; i < n; ++i) {
        res += arr[i] - arr[t] >= 0 ? arr[i] - arr[t] : arr[t] - arr[i];
    }
    printf("%d", res);
    return 0;
}
