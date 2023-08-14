#include <iostream>
using namespace std;
const int N = 12010;
int w[N], v[N];
int f[N];
int cnt;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int a, b, s, k = 1;
        cin >> a >> b >> s;
        while (k <= s)
        {
            cnt ++;
            v[cnt] = k * a;
            w[cnt] = k * b;
            s -= k;
            k *= 2;
        }
        if(s > 0)
        {
            cnt ++;
            v[cnt] = s * a;
            w[cnt] = s * b;
        }
    }
    n = cnt;
    for (int i = 1; i <= n; i++)
    {
        for(int j = m; j >= v[i]; j--)
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[m];
}