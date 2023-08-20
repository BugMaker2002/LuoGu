#include <iostream>
#include <string.h>
using namespace std;
const int N = 21, M = 1 << N;
int w[N][N];
int f[M][N];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> w[i][j];
        }
    }
    //别忘了这一步
    memset(f, 0x3f, sizeof(f));
    f[0][0] = 0;
    //比如f[11101][4]就表示经过点0、2、3、4且终点是4的最短距离
    //注意，二进制串是逆序的，即依次表示编号为(n-1)~0的点是否经过
    for(int i = 0; i < 1 << n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if((i >> j) & 1)
            {
                for (int k = 0; k < n; k++)
                {
                    if ((i >> k) & 1)
                    {
                        //i - (1 << j)表示从串i当中去掉j号点（即不打算经过这个点）
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);
                    }
                }
            }
        }
    }
    cout << f[(1 << n) - 1][n - 1];
}