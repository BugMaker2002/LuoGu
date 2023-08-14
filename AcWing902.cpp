#include <iostream>
using namespace std;
const int N = 1010;
//f[i][j]表示将a的前i个字母与b的前j个字母匹配
//所需要的最少操作次数
int f[N][N];
char a[N], b[N];
int main()
{
    int n, m;
    cin >> n >> a + 1 >> m >> b + 1;
    for (int i = 1; i <= n; i++)
    {
        //将a的前i个字母变为空，只能删除i次
        f[i][0] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        //空变为b的前i个字母，只能增加i次
        f[0][i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            //如果a的前i个与b的前j - 1个匹配，那我们只需要将a的第i个删掉（一次操作）
            //如果a的前i - 1个与b的前j个匹配，那我们只需要将a后面加一个元素（一次操作）
            f[i][j] = min(f[i][j - 1] + 1, f[i - 1][j] + 1);
            //如果a的第i个和b的第j个相等，那么我们不需要操作
            //否则将a的第i个替换为b[j]
            if (a[i] == b[j])
            {
                f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            }
            else
            {
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
    }
    cout << f[n][m];
}