#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n --)
    {
        int a;
        cin >> a;
        int res = a;
        for (int i = 2; i <= a / i; i++)
        {
            //注意此处跟前面的质因数分解代码有所不同
            //我们此处加了一个if条件判断，否则的话res = res / i * (i - 1);
            //会被执行α幂次，因此得把计算公式放在while循环外面，使之只执行一次
            if (a % i == 0)
            {
                //注意，此处不可调转顺序写成res = res * (i - 1) / i;
                //这样的话会使res的结果int上溢
                res = res / i * (i - 1);
                while (a % i == 0)
                {
                    a /= i;
                }
            }
        }
        if(a > 1) res = res / a * (a - 1);
        cout << res << endl;
    }
}