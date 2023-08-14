#include <iostream>
#include <string.h>
using namespace std;
const int N = 1010, M = 13;
char str[N][M];
int f[M][M];
int edit_d(char a[], char b[])
{
    int la = strlen(a + 1);
    int lb = strlen(b + 1);
    for(int i = 1; i <= la; i++)
    {
        f[i][0] = i;
    }
    for(int i = 1; i <= lb; i++)
    {
        f[0][i] = i;
    }
    for(int i = 1; i <= la; i++)
    {
        for(int j = 1; j <= lb; j++)
        {
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            if(a[i] == b[j])
            {
                f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            }
            else
            {
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
    }
    return f[la][lb];
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {   
        cin >> str[i] + 1;
    }
    while (m --)
    {
        char a[M];
        int limit, res = 0;
        cin >> a + 1 >> limit;
        for (int i = 0; i < n; i++)
        {   
            if (edit_d(str[i], a) <= limit)
            {
                res ++;
            }
        }
        cout << res << endl;
    }
}