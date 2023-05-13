#include <iostream>
#include <cmath>
using namespace std;
long long a[501]={0};
long long cp(int n)
{
    long long result=1;
    for (int i = 1; i <= n; i++)
    {
        result*=2;
    }
    return result;
}
int main()
{
    int p;
    cin>>p;
    int num1=p/32;
    int num2=p-num1*32;
    long long x=cp(32);
    a[500]=1;
    /**
     * @brief 
     * 为了加快速度，我们在前num1轮对每个数乘以2^32，由于p/32并不一定刚好整除，因此我们在剩下的num1轮当中对每个数每次乘2
     */
    for (int i = 1; i <= num1; i++)
    {
        for (int j = 500; j >= 1; j--)
        {
            a[j]*=x;
        }
        for (int j = 500; j >= 1; j--)
        {
            a[j-1]+=a[j]/10;
            a[j]%=10;
        }
    }
    for (int i = 1; i <= num2; i++)
    {
        for (int j = 500; j >= 1; j--)
        {
            a[j]*=2;
        }
        for (int j = 500; j >= 1; j--)
        {
            a[j-1]+=a[j]/10;
            a[j]%=10;
        }
    }
    a[500]--;
    cout<<(int)(p*log10(2)+1)<<endl;
    for (int i = 1; i <= 500; i++)
    {
        cout<<a[i];
        if (i%50==0)
        {
            cout<<endl;
        }
    }
}