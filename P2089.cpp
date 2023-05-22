#include <iostream>
using namespace std;
int ans[60005][11];
int n,a[11];
//记录方案的总数
int sum=0;
/**
 * @brief 表示当前配料为i（1~10），总量为m kg
 * @param i 
 * @param m 
 */
void trys(int i,int m)
{
    if (i>10)
    {
        if (m==n)
        {
            sum++;
            for (int k = 1; k <= 10; k++)
            {
                ans[sum][k]=a[k];
            }
        }
        return;
    }
    for (int j = 1; j <= 3; j++)
    {
        a[i]=j;
        //如果超过了要求，那么后面的就可以直接忽略
        if (m+j>n)
        {
            break;
        }
        trys(i+1,m+j);
    }
}
int main()
{
    cin>>n;
    //从第1个配料开始，初始总量为0
    trys(1,0);
    cout<<sum<<endl;
    for (int i = 1; i <= sum; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
}