#include <iostream>
using namespace std;
/**
 * 注意点：
 * 1. 任意字符不可以映射成0，否则会出现不同的字符串都映射
 * 成0的情况，比如A,AA,AAA皆为0
 * 2. 冲突问题：通过巧妙设置P (131 或 13331) , Q（2^64）的值，
 * 一般可以理解为不产生冲突。
 */
typedef unsigned long long ULL;// 0 ~ 2^64 - 1, 溢出相当于取模
const int N = 100003, P = 131;
ULL h[N], p[N];
/**
 * 如何去求部分子串的哈希值呢？
 * 以ABCDE和ABC为例，如何求DE的哈希值？
 * 容易知道ABCDE的哈希值为AP^4+BP^3+CP^2+DP+E
 * ABC的哈希值为AP^2+BP+C
 * 所以我们首先将ABC扩展为ABC00，则其哈希值为：AP^4+BP^3+CP^2
 * 我们将ABCDE减去ABC00即可得到DE的哈希值为DP+E
 * 所以总结公式就是：h[r] - h[l - 1] * p[r - l + 1]
 */
ULL getHash(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}
int main()
{
    int n, m;
    char str[N];
    cin >> n >> m;
    //字符串数组下标从1开始存储
    cin >> str + 1;
    //初始化工作
    p[0] = 1;
    for (int i = 1; i <= n; i++) 
    {
        /**
         * p数组存放的是P的n次方
         * h数组存的是从1~i的字符串的哈希值
         */
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }
    while (m --)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (getHash(l1, r1) == getHash(l2, r2))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}