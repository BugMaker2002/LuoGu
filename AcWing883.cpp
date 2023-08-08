#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const int N = 110;
//eps别手欠定义成int了
double eps = 1e-6;
int n;
double a[N][N];
int gauss()
{
    //c代表列，r代表行
    int c, r;
    for (c = 0, r = 0; c < n; c++)
    {
        int t = r;
        //找出第c列绝对值最大元素所在行
        for(int i = r; i < n; i++)
        {
            if (fabs(a[i][c]) > fabs(a[t][c]))
            {
                t = i;
            }
        }
        //如果第c列绝对值最大元素为0，那也就没必要找了
        if(fabs(a[t][c]) < eps)
        {
            continue;
        }
        //交换
        for (int i = c; i <= n; i++)
        {
            swap(a[t][i], a[r][i]);
        }
        //除
        for (int i = n; i >= c; i--)
        {
            a[r][i] /= a[r][c];
        }
        for (int i = r + 1; i < n; i++)
        {
            if (fabs(a[i][c]) > eps)
            {
                for (int j = n; j >= c; j--)
                {
                    a[i][j] -= a[i][c] * a[r][j];
                }
            }
        }
        r ++;
    }
    if (r < n)
    {
        for (int i = r; i < n; i++)
        {
            if (fabs(a[i][n]) > eps)
            {
                //无解
                return 0;
            }
        }
        //有无穷多组解
        return 2;
    }
    for (int i = n - 1; i >= 0 ; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            a[i][n] -= a[j][n] * a[i][j];
        }
    }
    //有唯一解
    return 1;
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    int t = gauss();
    if (t == 0)
    {
        cout << "No solution";
    }
    else if(t == 1)
    {
        for(int i = 0; i < n; i++)
        {
            cout << fixed << setprecision(2) <<
             a[i][n] << endl;;
        }
    }
    else
    {
        cout << "Infinite group solutions";
    }
}