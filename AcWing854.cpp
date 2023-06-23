#include <iostream>
#include <string.h>
using namespace std;
const int N = 210, INF = 1e9;
int d[N][N];
int main()
{
    int n, m, k, x, y, z;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i == j)
            {
                d[i][j] = 0;
            }
            else
            {
                d[i][j] = INF;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        //要防止重边
        d[x][y] = min(d[x][y], z);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;
        if (d[x][y] > INF / 2)
        {
            cout<<"impossible"<<endl;
        }
        else
        {
            cout<<d[x][y]<<endl;
        }
    }
}