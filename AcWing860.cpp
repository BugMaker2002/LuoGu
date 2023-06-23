#include <iostream>
#include <string.h>
using namespace std;
const int N = 100100;
//因为是无向图，采用我们邻接表的方式存储需要存储两次相同的边，所以M的大小要是2倍以上
const int M = 200100;
int e[M], ne[M], h[N], idx, n, m;
//存储染色的数组
int d[N];
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
bool dfs(int v, int color)
{
    d[v] = color;
    for (int i = h[v]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (d[j] == -1)
        {
            if (!dfs(j, !color))
            {
                return false;
            }
        }
        if (d[j] == color)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    memset(d, -1, sizeof(d));
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == -1)
        {
            if(!dfs(i, 0))
            {
                cout<<"No";
                return 0;
            }
        }
    }
    cout<<"Yes";
    return 0;
}