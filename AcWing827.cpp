#include <iostream>
using namespace std;
const int M = 100100;
int e[M], l[M], r[M], idx;
void init()
{
    //初始化操作，第一个点的右边是1，第二个点的左边是0
    //0和1代表头和尾
    r[0] = 1;
    l[1] = 0;
    //此时已经用掉两个点了
    idx = 2;
}
//只用写在第k个点的右边插入x即可（如果是想在
//第k个点的左边插入直接调用add(l[k], x)即可
void add(int k, int x)
{
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx;
    idx ++;
}
void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}
int main()
{
    int m;
    cin >> m;
    init();
    while(m --)
    {
        string s;
        cin >> s;
        if(s == "L")
        {
            int x;
            cin >> x;
            add(0, x);
        }
        else if(s == "R")
        {
            int x;
            cin >> x;
            add(l[1], x);
        }
        else if(s == "D")
        {
            int k;
            cin >> k;
            remove(k + 1);
        }
        else if(s == "IL")
        {
            int k, x;
            cin >> k >> x;
            add(l[k + 1], x);
        }
        else if(s == "IR")
        {
            int k, x;
            cin >> k >> x;
            add(k + 1, x);
        }
    }
    for (int i = r[0]; i != 1; i = r[i])
    {
        cout << e[i] << " ";
    }
}