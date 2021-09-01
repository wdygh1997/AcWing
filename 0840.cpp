#include <cstdio>
#include <cstring>

const int N = 200003, null = 0x3f3f3f3f;

int hash[N];

int find(int x)
{
    int t = (x % N + N) % N;
    while (hash[t] != null && hash[t] != x)
        t = (t+1) % N;
    return t;
}

int main()
{
    int n;
    scanf("%d", &n);
    memset(hash, 0x3f, sizeof hash);
    for (int i = 0; i < n; i++) {
        char op[5];
        int x;
        scanf("%s%d", op, &x);
        int k = find(x);
        if (op[0] == 'I') hash[k] = x;
        else {
            if (hash[k] != null)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
