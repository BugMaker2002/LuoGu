#include <iostream>
using namespace std;
typedef long long LL;
LL getQ(int a, int k, int p)
{
    LL res = 1;
    while (k)
    {
        //参考二进制，只有该位为1才需要加
        if (k & 1)
        {
            res = res * a % p;
        }
        //右移
        k = k >> 1;
        //这里也要记得转换为LL，因为a的平方可能会很大
        //不管要不要加（即k的该位是0还是1，我们都往前算a（
        //每次将a去平方），因为：
        //a^2^0 = a
        //a^2^1 = a^2
        //a^2^2 = a^4
        //a^2^3 = a^8
        //a^2^4 = a^16
        //a^2^5 = a^32
        a = (LL)a * a % p;
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    while (n --)
    {
        int a, k, p;
        cin >> a >> k >> p;
        cout << getQ(a, k, p) << endl;
    }
}