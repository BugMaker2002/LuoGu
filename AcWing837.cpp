#include <iostream>
using namespace std;
const int N = 100100;
int n, m, p[N], size_of_block[N];
int find(int x)
{
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}
int main()
{
    cin >> n >> m;
    //初始化
    for(int i = 1; i <= n; i++)
    {
        p[i] = i;
        size_of_block[i] = 1;
    }
    char op[4];
    while (m --)
    {
        cin >> op;
        if(op[0] == 'C')
        {
            int a, b;
            cin >> a >> b;
            //如果a和b本身就在一个连通块当中的话，我们就直接跳过
            if (find(a) == find(b))
            {
                continue;
            }
            //注意，这两句的顺序不能调换！
            size_of_block[find(b)] += size_of_block[find(a)];
            p[find(a)] = find(b);
        }
        else if (op[1] == '1')
        {
            int a, b;
            cin >> a >> b;
            //如果a和b本身就在一个连通块当中的话，我们就直接跳过
            if (find(a) == find(b))
            {
                cout << "Yes" <<endl;
            }
            else
            {
                cout << "No" <<endl;
            }
        }
        else if (op[1] == '2')
        {
            int a;
            cin >> a;
            cout << size_of_block[find(a)] <<endl;
        }
    }
}