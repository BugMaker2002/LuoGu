#include <iostream>
using namespace std;
const int N = 110;
int a[N][N], n;
int gauss()
{
    int c, r;
    for(c = 0, r = 0; c < n; c++) 
    {
        int t = -1;
        for (int i = r; i < n; i++)
        {
            if (a[i][c])
            {
                t = i;
                break;
            }
        }
        if (t == -1)
        {
            continue;
        }
        for (int i = n; i >= c; i--)
        {
            swap(a[t][i], a[r][i]);
        }
        //异或对这题没有对应的除的步骤
        // for (int i = n; i >= c; i--)
        // {
        //     a[t][i] ^= a[c][i];
        // }
        for (int i = r + 1; i < n; i++)
        {
            if(a[i][c])
            {
                for (int j = n; j >= c; j--)
                {
                    a[i][j] ^= a[r][j];
                }
            }
        }
        r ++;
    }
    if(r < n)
    {
        for (int i = r; i < n; i++)
        {
            if (a[i][n])
            {
                return 0;
            }
        }
        return 2;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for(int j = i + 1; j <= n; j++)
        {
            if(a[i][j])
            {
                a[i][n] ^= a[j][n];
            }
        }
    }
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
            cout << a[i][n] << endl;
        }
    }
    else
    {
        cout << "Multiple sets of solutions";
    }
}