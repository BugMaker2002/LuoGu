/**
 * 首先， 在带扩展域的并查集 中 x 不再只是一个 值，而是一个事件； 
规定    x       为 "事件 x 为 A 类动物"；
规定  x + N     为 "事件 x 为 B 类动物"；
规定 x + N * 2  为 "事件 x 为 C 类动物"；

p[find(X)] = find(Y) 表示 
        事件 X 为 A 类动物 和 事件 Y 为 A 类动物 同时发生

X 与 Y 为同种动物 等价于 
        p[ find(X) ] = find(Y);
        p[ find(X + N)] = find(Y + N);
        p[ find(X + N * 2)] = find(Y + N * 2);



p[find(X)] = find(Y + N) 表示
        事件 X 为 A 类动物 和 事件 Y 为 B 类动物 同时发生

X 吃 Y 等价于
        p[ find(X) ] = find(Y + N);
        p[ find(X + N)] = find(Y + N * 2);
        p[ find(X + N * 2)] = find(Y);
 * 
 */
#include <iostream>
using namespace std;
const int N = 50010;
int p[3 * N];
int find(int x)
{
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}
int main()
{
    int n, k, ans = 0;
    cin >> n >> k;
    //因为后面涉及到的操作全是+N或者+2*N，因此此处初始化也要是0~3*N
    for (int i = 0; i < 3 * N; i++)
    {
        p[i] = i;
    }
    while (k --)
    {
        int d, x, y;
        cin >> d >> x >> y;
        if(x > n || y > n) 
        {
            ans ++;
            continue;
        }
        else if (x == y)
        {
            if(d == 2)
            {
                ans ++;
            }
            continue;
        }
        else if(d == 1)
        {
            //如果x吃y或者y吃x，那就说明是假话
            //注意，这里不用把x是A类，y是B类；x是B类，y是A类；x是B类，y是C类；x是C类，y是B类；
            //x是C类，y是A类；x是A类，y是C类；六种情况全判断一遍，因为我们在设定x和y互吃关系时
            //将这六种情况全部设定了，所以只用挑一种出来判断就行
            if (find(x) == find(y + N) || find(x + N) == find(y))
            {
                ans ++;
                continue;
            }
            p[find(x)] = find(y);
            p[find(x + N)] = find(y + N);
            p[find(x + 2 * N)] = find(y + 2 * N);
        }
        else
        {
            //如果y吃x或者两者为同类，那就说明是假话
            if (find(x) == find(y) || find(x + N) == find(y))
            {
                ans ++;
                continue;
            }
            p[find(x)] = find(y + N);
            p[find(x + N)] = find(y + 2 * N);
            p[find(x + 2 * N)] = find(y);
        }
    }
    cout << ans << endl;
}