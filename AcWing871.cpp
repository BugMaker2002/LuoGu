#include <iostream>
#include <unordered_map>
using namespace std;
const int mod = 1e9 + 7;
typedef long long LL;
int main()
{
    int n;
    cin >> n;
    unordered_map<int, int> m;
    while (n --)
    {
        int x;
        cin >> x;
        //这里千万不要把x和n写混了，有时候写着写着就容易把
        //x写成n，这样的话必定WA!!!
        for (int i = 2; i <= x / i; i++)
        {
            while (x % i == 0)
            {
                x /= i;
                m[i] ++;
            }
        }
        if (x > 1)
        {
            m[x] ++;
        }
    }
    LL ans = 1;
    for (auto t : m)
    {
        int p = t.first, a = t.second;
        LL ans_loc = 1;
        while (a --)
        {
            ans_loc = (ans_loc * p + 1) % mod;
        }
        ans = ans * ans_loc % mod;
    }
    cout << ans << endl;
}