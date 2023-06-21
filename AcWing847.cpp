#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int n, m, a, b, idx;
int e[200100], ne[200100], h[100100];
int d[100100];
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
int bfs(int k)
{
    queue<int>q;
    q.push(k);
    d[1] = 0;
    while(q.size()!=0)
    {
        int u = q.front();
        q.pop();
        for(int i = h[u]; i != -1; i = ne[i])
        {
            int v = e[i];
            //因为可能存在自环，所以得判断一下是不是遍历回自己了
            if (d[v] == -1) 
            {
                q.push(v);
                d[v] = d[u] + 1;
            }   
        }
    }
    return d[n];
}
int main()
{
    cin>>n>>m;
    memset(h, -1, sizeof(h));
    //因为不存在则输出-1，所以d数组应该初始化为-1
    memset(d, -1, sizeof(d));
    for(int i = 0; i < m; i ++)
    {
        cin>>a>>b;
        add(a, b);
    }
    cout<<bfs(1);
}