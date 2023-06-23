#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int M = 200100;
const int N = 100100;
int n, m, p[N];
struct Edge
{
    int a;
    int b;
    int w;
    bool operator<(const Edge& W) const
    {
        return w < W.w;
    }
}edges[M];
int find(int x)
{
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}
void Kruskal()
{
    //初始化并查集
    for(int i = 1; i <= n; i++)
    {
        p[i] = i;
    }
    sort(edges, edges + m);
    int res = 0, cnt = 0;
    for(int i = 0; i < m; i++)
    {
        int a = edges[i].a;
        int b = edges[i].b;
        int w = edges[i].w;
        a = find(a);
        b = find(b);
        if(a != b)
        {
            //合并并查集
            p[a] = b;
            res += w;
            cnt ++;
        }
    }
    if (cnt < n - 1)
    {
        cout<<"impossible";
    }
    else
    {
        cout<<res;
    }
}
int main()
{
    cin >> n >> m;
    int a, b, w;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }
    Kruskal();
}
