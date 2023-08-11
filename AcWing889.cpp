#include <iostream>
using namespace std;
const int N = 200100, mod = 1e9 + 7;
typedef long long LL;
int fact[N], infact[N];
int qmi(int a, int k)
{
    int res = 1;
    while (k)
    {
        if(k & 1) res = (LL)res * a % mod;
        k = k >> 1;
        a = (LL) a * a % mod;
    }
    return res;
}
void init()
{
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (LL)fact[i - 1] * i % mod;
        infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2) % mod;
    }
}
int main()
{
    init();
    int n;
    cin >> n;
    cout << (LL) fact[2 * n] * infact[n] % mod * infact[n] % mod * qmi(n + 1, mod - 2) % mod;
}