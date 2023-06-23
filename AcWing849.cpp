#include <iostream>
#include <string.h>
using namespace std;
const int N = 503;
int n, m, a, b, c;
int g[N][N], dist[N], st[N];
int Dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    for(int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
            {
                t = j;
            }
        }
        for (int j = 1; j <= n; j++)
        {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
        st[t] = true;
    }
    if(dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}
int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof(g));
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }
    cout<<Dijkstra();
}