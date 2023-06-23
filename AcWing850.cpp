#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
const int N = 150010;
//w数组用于存储边的权重
int h[N], w[N], e[N], ne[N], dist[N], st[N];
int n, m, idx, x, y, z;
typedef pair<int, int> PII;
void add(int x, int y, int z)
{
    e[idx] = y;
    w[idx] = z;
    ne[idx] = h[x];
    h[x] = idx++;
}
int Dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>>heap;
    //放入初始编号为1的结点，距离为0
    heap.push({0, 1});
    while (!heap.empty())
    {
        auto t = heap.top();
        heap.pop();
        int distance = t.first;
        int num = t.second;
        if (st[num])
        {
            continue;
        }
        for (int i = h[num]; i != -1; i = ne[i])
        {
            int v = e[i];
            if (st[v])
            {
                continue;
            }
            if(dist[v] > w[i] + distance)
            {
                dist[v] = w[i] + distance;
                heap.push({dist[v], v});
            }
        }
        st[num] = true;
    }
    if (dist[n] == 0x3f3f3f3f)
    {
        return -1;
    }
    return dist[n];
}
int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        add(x, y, z);
    }
    cout<<Dijkstra();
}