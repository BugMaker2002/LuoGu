#include <iostream>
#include <string.h>
using namespace std;
const int N = 510;
const int M = 100100;
int e[M], ne[M], h[N], idx, n1, n2, m;
bool st[N];
int match[N];
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
bool find(int x)
{
    for(int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            st[j] = true;
            if(match[j] == 0 || find(match[j]))
            {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int u, v, res = 0;
    cin >> n1 >> n2 >> m;
    memset(h, -1, sizeof(h));
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        // 保存图，因为只从一遍找另一边，所以该无向图只需要存储一个方向
        add(u, v);
    }
    for(int i = 1; i <= n1; i++)
    {
        memset(st, false, sizeof(st));
        if(find(i)) res++;
    }
    cout<<res;
}