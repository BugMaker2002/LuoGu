#include <iostream>
using namespace std;
const int N = 1000100;
typedef long long LL;
//Primes[N]数组存放的全是质数
int Primes[N], cnt;
//st[i] = true表示数i不是质数
bool st[N];
int phi[N];
LL getAll(int n)
{
    phi[1] = 1;
    LL res = 1;
    for(int i = 2; i <= n; i ++)
    {
        if(!st[i])
        {
            Primes[cnt ++] = i;
            phi[i] = i - 1;
        }
        for(int j = 0; Primes[j] <= n / i; j++)
        {
            st[Primes[j] * i] = true;
            if (i % Primes[j] == 0)
            {
                phi[Primes[j] * i] = phi[i] * Primes[j];
                break;
            }
            phi[Primes[j] * i] = phi[i] * (Primes[j] - 1);
        }
        res = res + phi[i];
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    cout << getAll(n) << endl;
}