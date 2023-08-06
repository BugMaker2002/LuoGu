#include <iostream>
#include <unordered_map>
using namespace std;
//注意：10^9+7是1e9+7，而不是10e9+7
const int mod = 1e9 + 7;
typedef long long LL;
int main()
{
    int n;
    LL ans = 1;
    cin >> n;
    unordered_map<int, int> m;
    while (n--)
    {
        int x;
        cin >> x;
        for(int i = 2; i <= x / i; i++)
        {
            while (x % i == 0)
            {
                x /= i;
                m[i] ++;
            }
        }
        //千万别忘记这一步，将最后一个质数也得计数
        if (x > 1)
        {
            m[x] ++;
        }
    }
    for (auto t : m)  
    {
        //注意，这里不能图方便写成ans *= (t.second + 1) % mod;
        //因为这样的话ans就没被模，导致最后的数很大
        ans = ans * (t.second + 1) % mod;
    }
    cout << ans<< endl;
}