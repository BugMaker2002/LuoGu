#include <iostream>
using namespace std;
const int N = 100100;
const int M = 1000100;
int n, m;
//注意，这两个是char数组
char p[N], s[M];
int ne[M];
int main()
{
    cin >> n;
    //下标从1开始
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    cin >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> s[i];
    }
    //求ne数组
    for(int i = 2, j = 0; i <= n; i++)
    {
        //先while后for
        while(j && p[i] != p[j + 1]) j = ne[j];
        if(p[i] == p[j + 1]) j ++;
        ne[i] = j;
    }
    //求解步骤，与上述步骤差不多，注意这里是s和p进行比较
    //且j == n时要记得输出
    for (int i = 1, j = 0; i <= m; i++)
    {
        while(j && s[i] != p[j + 1]) j = ne[j];
        if(s[i] == p[j + 1]) j ++;
        if (j == n)
        {
            printf("%d ", i - n);
            j = ne[j];
        }
    }
}