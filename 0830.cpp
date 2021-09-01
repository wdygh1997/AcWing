#include <cstdio>

int stack[100010], top = -1;

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        while (top >= 0 && stack[top] >= x) top--;
        if (top == -1)
            printf("-1 ");
        else
            printf("%d ", stack[top]);
        stack[++top] = x;
    }
    return 0;
}
