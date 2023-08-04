#include <iostream>
using namespace std;
const int N = 100100;
//p数组用于存放每一个结点的父节点
int p[N];
int find(int x)
{
    if (p[x] != x)
    {
        //这一步在往上搜寻父节点的
        //同时将根节点的每个子节点全部直接连到了根节点上
        //这样做是为了节省后续查找操作的时间复杂度
        p[x] = find(p[x]);
    }
    return p[x];
}
int main()
{
    int n, m;
    cin >> n >> m;
    //初始化操作，初始时，每一个节点自成一派
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }
    char op[2];
    int a, b;
    while(m --)
    {
        cin >> op >> a >> b;
        // scanf("%s%d%d", &op, &a, &b);
        if (op[0] == 'Q')
        {
            if(find(a) == find(b))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else
        {
            p[find(a)] = find(b);
        }
    }
}