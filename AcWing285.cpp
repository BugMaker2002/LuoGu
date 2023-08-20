#include <iostream>
#include <string.h>
using namespace std;
const int N = 6010;
int h[N], e[N], ne[N], idx;
bool has_father[N];
int happy[N];
int f[N][2];
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}
void dfs(int x)
{
    f[x][1] = happy[x];
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        dfs(j);
        f[x][1] += f[j][0];
        f[x][0] += max(f[j][1], f[j][0]);
    }
}
int main()
{
    int n;
    cin >> n;
    memset(h, -1, sizeof(h));
    for (int i = 1; i <= n; i++)
    {
        cin >> happy[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        has_father[a] = true;
        add(b, a);
    }
    //找到根节点的编号
    int root = 1;
    while(has_father[root]) root ++;
    dfs(root);
    cout << max(f[root][1], f[root][0]);
}