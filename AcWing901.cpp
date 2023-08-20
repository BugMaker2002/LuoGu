#include <iostream>
#include <string.h>
using namespace std;
const int N = 310;
int f[N][N];
int h[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; 
int n, m;
int dp(int x, int y)
{
    if (f[x][y] != -1)
    {
        return f[x][y];
    }
    f[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int a = x + dx[i];
        int b = y + dy[i];
        if (a >= 1 && a <= n && b >= 1 && b <= m &&
        h[a][b] < h[x][y])
        {
            //注意这里是d(a, b)而不是f[a][b]
            f[x][y] = max(f[x][y], dp(a, b) + 1);
        }
    }
    return f[x][y];
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> h[i][j];
        }
    }
    memset(f, -1, sizeof(f));
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            res = max(res, dp(i, j));
        }
    }
    cout << res << endl;
}