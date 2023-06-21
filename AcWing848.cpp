#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
const int N = 100100;
int n, m, idx, a, b;
//d是我们存的点的入度信息
int e[N], ne[N], h[N], d[N];
vector<int>ans;
//ans存放队列中元素出队的顺序，即为拓扑排序的顺序
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
void topsort()
{
    queue<int>q;
    for (int i = 1; i <= n; i++)
    {
        if(d[i]==0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        ans.push_back(u);
        q.pop();
        for (int i = h[u]; i != -1; i = ne[i])
        {
            int v = e[i];
            d[v]--;
            if (d[v]==0)
            {
                q.push(v);
            }
        }
    }
    if (ans.size()!=n)
    {
        cout<<-1;
    }
    else
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout<<ans[i]<<" ";
        }
    }
}
int main()
{
    cin>>n>>m;
    memset(h, -1, sizeof(h));
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b;
        //在插边的过程当中记录各结点的入度
        d[b]++;
        add(a, b);
    }
    topsort();
}