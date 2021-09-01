#include <cstdio>
#include <vector>
#include <string>

using namespace std;

const int n = 1e5+10;

bool cmp(vector<int> &a, vector<int> &b)
{
    if (a.size() != b.size()) return a.size() > b.size();
    for (int i = a.size()-1; i >= 0; i--)
        if (a[i] != b[i])
            return a[i] > b[i];
    return true;
}

vector<int> sub(vector<int> &a, vector<int> &b)
{
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t = a[i]-t;
        if (i < b.size()) t -= b[i];
        c.push_back((t+10)%10);
        if (t < 0) t = 1;
        else t = 0;
    }
    while (c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}

int main()
{
    char s[n];
    string str;
    scanf("%s", s);
    str = s;
    vector<int> a;
    for (int i = str.size()-1; i>=0; i--) a.push_back(str[i] - '0');
    scanf("%s", s);
    str = s;
    vector<int> b;
    for (int i = str.size()-1; i>=0; i--) b.push_back(str[i] - '0');
    vector<int> c;
    if (cmp(a, b))
    {
        c = sub(a, b);
        for (int i = c.size()-1; i >= 0; i--) printf("%d", c[i]);
    }
    else
    {
        c = sub(b, a);
        printf("-");
        for (int i = c.size()-1; i >= 0; i--) printf("%d", c[i]);
    }
    return 0;
}
