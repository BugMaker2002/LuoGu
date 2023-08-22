#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100100;
int a[N];
typedef long long LL;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    LL res = 0;
    for (int i = 0; i < n; i++)
    {
        res += a[i] * (n - i - 1);
    }
    cout << res << endl;
}