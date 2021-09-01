#include <cstdio>

int n, m;
char p[100010], s[1000010];
int next[100010];

int main()
{
    scanf("%d", &n);
    scanf("%s", p);
    scanf("%d", &m);
    scanf("%s", s);

    next[0] = -1;
    for (int i = 1, j = -1; i < n; i++) {
        while (j >= 0 && p[j+1] != p[i]) j = next[j];
        if (p[j+1] == p[i]) j++;
        next[i] = j;
    }

    for (int i = 0, j = -1; i < m; i++) {
        while (j >= 0 && p[j+1] != s[i]) j = next[j];
        if (p[j+1] == s[i]) j++;
        if (j == n-1) {
            printf("%d ", i-j);
            j = next[j];
        }
    }
    return 0;
}
