#include <iostream>
using namespace std;
const int M = 20;
int p[M];
int n, m;
typedef long long LL;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> p[i];
    }
    //res用于存放最终的结果
    int res = 0;
    //1 << m即为1向左移m位，如m=2，那么就是1<=i<100，即
    //1<=i<=11即i依次取01,10,11这三个二进制串
    for (int i = 1; i < 1 << m; i++)
    {
        //t记录局部乘积
        int t = 1;
        //s记录i当中1的个数，方便我们待会计算是加还是减
        int s = 0;
        //因为i有m位
        for(int j = 0; j < m; j++)
        {
            if(i >> j & 1)
            {
                //这样的话也就没有计算的必要了（因为n除上比
                //自己小的数为0
                if ((LL)p[j] * t > n)
                {
                    t = -1;
                    break;
                }
                s ++;
                t *= p[j];
            }
        }
        if(t != -1)
        {
            if(s % 2 == 1)
            {
                res += n / t;
            }
            else
            {
                res -= n / t;
            }
        }
    }
    cout << res << endl;
}