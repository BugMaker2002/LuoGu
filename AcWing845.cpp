//参见题解https://www.acwing.com/solution/content/15149/
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
queue<string> q;
//d记录次数
unordered_map<string, int> d;
int bfs(string s)
{
    q.push(s);
    d[s] = 0;
    while (!q.empty())
    {
        //取队头的操作一定要放在while循环里面，放在外面不是sb么？
        string t = q.front();
        q.pop();
        int distance = d[t];
        if (t == "12345678x")
        {
            return d[t];
        }
        int k = t.find('x');
        int x = k / 3, y = k % 3;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i];
            int b = y + dy[i];
            //确保a和b在合法的范围内
            if(a >=0 && a <=2 && b >=0 && b <=2)
            {
                swap(t[k], t[a * 3 + b]);
                //如果交换后没出现过
                if(!d.count(t))
                {
                    q.push(t);
                    //只要我们引用了d[t]，d.count(t)就会+1
                    d[t] = distance + 1;
                }
                //交换回来，进行下一次循环判断
                swap(t[k], t[a * 3 + b]);
            }
        }
    }
    return -1;
}
int main()
{
    //将输入的矩阵转换为一串字符串
    string c, s;
    for (int i = 0; i < 9; i++)
    {
        cin >> c;
        s += c;
    }
    cout << bfs(s) << endl;
}