#include <iostream>
#include <string.h>
#include <set>
using namespace std;
const int N = 110, M = 10010;
int s[N], f[M];
int k, n;
int sg(int x)
{
    if (f[x] != -1)
    {
        return f[x];
    }
    set<int> Set;
    for (int i = 0; i < k; i++)
    {
        if (s[i] <= x)
        {
            Set.insert(sg(x - s[i]));
        }
    }
    for (int i = 0; ; i++)
    {
        if (!Set.count(i))
        {
            return f[x] = i;
        }
    }
}
int main()
{
    memset(f, -1, sizeof(f));
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> s[i];
    }
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        res ^= sg(x);
    }
    if (res)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}