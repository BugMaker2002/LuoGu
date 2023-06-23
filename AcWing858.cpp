#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 510, INF = 0x3f3f3f3f;
int n, m;
int g[N][N];
int dist[N];
bool st[N];
void Prim()
{
    memset(dist, 0x3f, sizeof(dist));
    bool isExist = true;
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        int t = -1;
        for(int j = 1; j <= n; j++)
        {
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
            {
                t = j;
            }
        }
        //如果最短距离的点都是负无穷，那么就不存在最小生成树了
        if(i && dist[t] == INF) 
        {
            isExist = false;
            break;
        }
        if (i)
        {
            res += dist[t];
        }
        st[t] = true;
        //更新其它点
        for(int j = 1; j <= n; j++)
        {
            dist[j] = min(dist[j], g[t][j]);
        }
    }
    if (isExist)
    {
        cout<<res;
    }
    else
    {
        cout<<"impossible";
    }
}
int main()
{
    cin >> n >> m;
    int u, v, w;
    memset(g, 0x3f, sizeof(g));
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        //因为是无向图，因此要添加两条边g[u][v]和g[v][u]
        g[u][v] = g[v][u] = min(g[u][v], w);
    }
    Prim();
}