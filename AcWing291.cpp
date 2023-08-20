#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
const int N = 12, M = 1 << N;
bool st[M];
long long f[N][M];
vector<vector<int>> states(M);
int main()
{
    int n, m;
    while (cin >> n >> m, n || m)
    {
        //先去除同一列有奇数个0的情况
        for(int i = 0; i < (1 << n); i++)
        {
            int cnt = 0;
            bool isValid = true;
            for(int j = 0; j < n; j++)
            {
                //如果当前位是1
                //当要转化成二进制进行位运算时，必须用&而不能用&&
                if ((i >> j) & 1)
                {
                    //说明有奇数个0
                    if (cnt & 1)
                    {
                        isValid = false;
                        break;
                    }
                    //说明有偶数个0
                    cnt = 0;
                }
                //如果当前位是0
                else
                {
                    cnt ++;
                }
            }
            //再判断一下最后一段连续的0的个数是不是奇数个
            if (cnt & 1) isValid = false;
            st[i] = isValid;
        }
        for(int i = 0; i < (1 << n); i++)
        {
            //这一步别忘了
            states[i].clear();
            for(int j = 0; j < (1 << n); j++)
            {
                if ((i & j) == 0 && st[i | j])
                {
                    states[i].push_back(j);
                }
            }
        }
        //别忘了这一步
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j < (1 << n); j++)
            {
                for (auto k : states[j])
                {

                    f[i][j] += f[i - 1][k];
                }
            }
        }
        cout << f[m][0] << endl;
    }
}