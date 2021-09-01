#include <cstdio>
#include <vector>
#include <string>

using namespace std;

vector<int> mul(vector<int> &A, int b)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t; i ++ )
    {
        if (i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main()
{
    string str;
    char s[100010];
    int b;
    scanf("%s %d", s, &b);
    str = s;
    vector<int> A;
    for (int i = str.size()-1; i>=0; i--) A.push_back(str[i] - '0');
    vector<int> C = mul(A, b);
    for (int i = C.size()-1; i >= 0; i--) printf("%d", C[i]);
    return 0;
}
