#include <cstdio>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> heap;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d", &t);
        heap.push(t);
    }
    int res = 0;
    while (heap.size() > 1) {
        int a = heap.top();
        heap.pop();
        int b = heap.top();
        heap.pop();
        heap.push(a+b);
        res += a+b;
    }
    printf("%d", res);
    return 0;
}
