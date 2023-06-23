#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
const int N = 100100;
int h[N], e[N], ne[N], w[N];
bool st[N];
int dist[N], cnt[N];
int idx, n, m;
void add(int x, int y, int z)
{
    e[idx] = y;
    w[idx] = z;
    ne[idx] = h[x];
    h[x] = idx++;
}
bool spfa()
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
        st[t] = false;
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int v = e[i];
            if(dist[v] > dist[t] + w[i])
            {
                dist[v] = dist[t] + w[i];
                cnt[v] = cnt[t] + 1;
                if(!st[v])
                {
                    q.push(v);
                    st[v] = true;
                }
                if (cnt[v] >= n) 
                {
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    cin >> n >> m;
    int x, y, z;
    memset(h, -1, sizeof(h));
    for(int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        add(x, y, z);
    }
    if(spfa())
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
}