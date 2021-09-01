#include <cstdio>

int queue[1000010], front = 0, rear = 0, a[1000010];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
    {
        if (front != rear && i-queue[front]+1 > k)
            front = (front+1) % 1000010;
        while (front != rear && a[queue[(rear-1+1000010) % 1000010]] >= a[i])
            rear = (rear-1 + 1000010) % 1000010;
        queue[rear] = i;
        rear = (rear+1) % 1000010;
        if (i >= k-1)
            printf("%d ", a[queue[front]]);
    }
    printf("\n");
    front = rear = 0;
    for (int i = 0; i < n; i++)
    {
        if (front != rear && i-queue[front]+1 > k)
            front = (front+1) % 1000010;
        while (front != rear && a[queue[(rear-1 + 1000010) % 1000010]] <= a[i])
            rear = (rear-1 + 1000010) % 1000010;
        queue[rear] = i;
        rear = (rear+1) % 1000010;
        if (i >= k-1)
            printf("%d ", a[queue[front]]);
    }
    return 0;
}
