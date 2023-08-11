#include <iostream>
#include <vector>
using namespace std;
const int N = 5010;
int primes[N], cnt;
bool st[N];
int sum[N];
void get_primes(int n)
{
    for(int i = 2; i <= n; i++)
    {
        if(!st[i])
        {
            primes[cnt ++] = i;
        }
        for(int j = 0; primes[j] <= n / i; j ++)
        {
            st[i * primes[j]] = true;
            if(i % primes[j] == 0) break;
        }
    }
}
vector<int> mul(vector<int> res, int p)
{   
    vector<int> c;
    int t = 0;
    for (int i = 0; i < res.size(); i++)
    {
        t += p * res[i];
        c.push_back(t % 10);
        t /= 10;
    }
    while (t)
    {
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}
int get(int n, int p)
{
    int sum = 0;
    while (n)
    {
        sum += n / p;
        n /= p;
    }
    return sum;
}
int main()
{
    int a, b;
    cin >> a >> b;
    get_primes(a);
    for (int i = 0; i < cnt; i++)
    {
        int p = primes[i];
        sum[i] = get(a, p) - get(b, p) - get(a - b, p);
    }
    vector<int> res;
    res.push_back(1);
    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < sum[i]; j++)
        {
            res = mul(res, primes[i]);
        }
    }
    for (int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i];
    }
    
}