#include <cstdio>
#include <string>
#include <vector>

using namespace std;

vector<int> add(vector<int> &a, vector<int> &b)
{
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t += a[i];
        if (i < b.size()) t += b[i];
        c.push_back(t%10);
        t /= 10;
    }
    if (t) c.push_back(t);
    return c;
}

int main()
{
    char s[100010];
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
    if (a.size() >= b.size())
        c = add(a, b);
    else
        c = add(b, a);
    for (int i = c.size()-1; i>=0; i--) printf("%d", c[i]);
    return 0;
}
