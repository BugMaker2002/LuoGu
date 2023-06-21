#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int h[100100], ne[200100], e[200100];
bool st[100100];
int idx, ans = 100100, n;
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
//返回以u为根的子树当中点的数量
int dfs(int u)
{
    st[u] = true;
    int res = 0, sum = 1;
    for(int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            int s = dfs(j);
            res = max(res, s);
            sum += s;
        }
    }
    res = max(res, n - sum);
    ans = min(ans, res);
    return sum;
}
int main()
{
    int a, b;
    cin >> n;
    memset(h, -1, sizeof(h));
    for (int i = 0; i < n; i++)
    {
        cin >> a>>b;
        add(a, b);
        add(b, a);
    }
    dfs(1);
    cout<<ans;
}
