#include <iostream>
#include <string.h>
using namespace std;
//为什么N要取成100003呢？因为100003是大于100000的第一个质数
const int N = 100003;
/**
 * 采用拉链法
 */
int e[N], ne[N], h[N], idx;
void insert(int x)
{
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx ++;
}
bool find(int x)
{
    //这样散列是为了处理负数的问题，因为负数取模结果还是负数
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i])
    {
        int u = e[i];
        if (u == x) 
        {
            return true;
        }
    }
    return false;
}
int main()
{
    memset(h, -1, sizeof(h));
    int n;
    cin >> n;
    while (n --)
    {
        char op[2];
        int x;
        cin >> op >> x;
        if (op[0] == 'I')
        {
            insert(x);
        }
        else
        {
            if (find(x))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
}