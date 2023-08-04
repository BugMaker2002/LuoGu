#include <iostream>
using namespace std;
//由于是转化为二进制放到Trie树上，因此每一个数要转化为32位bit
//总共有100100个数，所以M = 32 * N
const int N = 100100, M = 32 * N;
int son[M][2], idx;
int a[N];
int insert(int x)
{
    //记住p的定义一定要放在最外面，不要放在for循环里面
    int p = 0;
    for(int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        //son数组初始化全为0
        if(!son[p][u])
        {
            son[p][u] = ++ idx;
        }
        p = son[p][u];
    }
}
//寻找所有数当中与数x相异或的最大值
int search(int x)
{
    int res = 0, p = 0;
    for(int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        //如果存在相异的bit，则跳转到这个分支
        //并且res = res * 2 + 1;
        if(son[p][!u])
        {
            p = son[p][!u];
            res = res * 2 + 1;
        }
        //如果存在相异的bit，不跳转到这个分支
        //res = res * 2;
        else
        {
            p = son[p][u];
            res = res * 2 + 0;
        }
    }
    return res;
}
int main()
{
    int n, ans = 0;
    cin >> n;
    //不要忘记首先插入数据
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }
    for(int i = 0; i < n; i++)
    {
        ans = max(ans, search(a[i]));
    }
    cout << ans << endl;
}