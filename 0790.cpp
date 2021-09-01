#include <cstdio>

double eps = 1e-8, n;

double BinarySearch(double l, double r)
{
    while (r-l > eps)
    {
        double m = (l+r)/2;
        if (m*m*m >= n) r = m;
        else l = m;
    }
    return l;
}

int main()
{
    scanf("%lf", &n);
    printf("%.6f", BinarySearch(-10000, 10000));
    return 0;
}
