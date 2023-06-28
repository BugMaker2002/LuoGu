#include <iostream>
using namespace std;
const int N = 1000100;
bool st[N];
int Primes[N], cnt;
void getPrimes(int n)
{
    for(int i = 2; i <= n; i++)
    {
        if (!st[i]) 
        {
            Primes[cnt++] = i;
        }
        for (int j = 0; Primes[j] <= n / i; j ++) 
        {
            st[i * Primes[j]] = true;
            if (i % Primes[j] == 0)
            {
                break;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    getPrimes(n);
    cout << cnt;
}