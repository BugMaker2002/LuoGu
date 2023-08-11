#include <iostream>
#include <string.h>
#include <set>
using namespace std;
const int N = 110;
int f[N];
int n;
int sg(int x)
{
    if(f[x] != -1) return f[x];
    set<int>Set;
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            Set.insert(sg(i) ^ sg(j));
        }
    }
    for(int i = 0; ; i++)
    {
        if(!Set.count(i))
        {
            return f[x] = i;
        }
    }
}
int main()
{
    memset(f, -1, sizeof(f));
    cin >> n;
    int res = 0;
    for(int i = 0; i < n; i++)
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