#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
const int N = 100100;
int h[N], e[N], ne[N], w[N];
int n, m, idx;
int dist[N];
bool st[N];
void add(int x, int y, int z)
{
    e[idx] = y;
    w[idx] = z;
    ne[idx] = h[x];
    h[x] = idx++;
}
void spfa()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    queue<int>q;
    for(int i = 1; i <= n; i++)
    {
        q.push(i);
        st[i] = true;
    }
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        //一定要记住，这里出队 后要记得将其重置为false，因为以后可能还要更新
        st[t] = false;
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int v = e[i];
            if(dist[v] > dist[t] + w[i])
            {
                dist[v] = dist[t] + w[i];
                if (!st[v])
                {
                    q.push(v);
                    st[v] = true;
                }
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f)
    {
        cout<<"impossible";
    }
    else
    {
        cout<<dist[n];
    }
}
int main()
{
    cin >> n >> m;
    int x, y, z;
    memset(h, -1, sizeof(h));
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        add(x, y, z);
    }
    spfa();
}