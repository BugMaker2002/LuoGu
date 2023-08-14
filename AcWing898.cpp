#include <iostream>
using namespace std;
const int N = 510, INF = 1e9;
int a[N][N], f[N][N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> a[i][j];
        }
    }
    //初始化f[i][j]数组，记住每个点邻近的点都得初始化成
    //-INF，因为题中数组a的值可以为负数，如果我们不将f数组
    //全部初始化成-INF的话后面取max就会取不存在的路径
    //所以i要从0到n+1，j要从0到i+1
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= i + 1; j++)
        {
            f[i][j] = -INF;
        }
    }
    f[1][1] = a[1][1];
    //注意下面必须从i等于2开始求起，因为第一行结果已经知道：
    //f[1][1] = a[1][1]不用再去求了
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            f[i][j] = max(f[i - 1][j] + a[i][j], f[i - 1][j - 1] + a[i][j]);
        }
    }
    int res = -INF;
    //看最后一行最大值是谁
    for (int i = 1; i <= n; i++)
    {
        res = max(res, f[n][i]);
    }
    cout << res;
}