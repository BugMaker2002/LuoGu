#include <iostream>
using namespace std;
const int N = 1010;
//f数组表示以第i个数结尾的子序列的最大长度
//a数组存放我们输入的数
int a[N], f[N];
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n;i ++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i ++)
    {
        f[i] = 1;
        for(int j = 1; j < i; j ++)
        {
            if(a[i] > a[j])
            {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i ++)
    {
        res = max(res, f[i]);
    }
    cout << res << endl;
}