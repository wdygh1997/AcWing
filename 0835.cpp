#include <cstdio>

int chd[100010][26], cnt[100010], idx = 1;

void insert(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int t = str[i] - 'a';
        if (!chd[p][t]) chd[p][t] = idx++;
        p = chd[p][t];
    }
    cnt[p]++;
}

int query(char str[])
{
    int p = 0;
    for (int i = 0; str[i]; i++)
    {
        int t = str[i] - 'a';
        if (!chd[p][t]) return 0;
        p = chd[p][t];
    }
    return cnt[p];
}

int main()
{
    int n;
    scanf("%d", &n);
    char op[5], str[100010];
    for (int i = 0; i < n; i++)
    {
        scanf("%s%s", op, str);
        if (op[0] == 'I')
            insert(str);
        else {
            int c = query(str);
            printf("%d\n", c);
        }
    }
    return 0;
}
