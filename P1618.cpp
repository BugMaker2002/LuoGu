#include <iostream>
using namespace std;
int main()
{
    int k1,k2,k3,a[10]={0},sum=0;
    bool alpha=false;
    cin>>k1>>k2>>k3;
    for (int i = 1; i <= 1000/k3; i++)
    {
        int b1=i*k1;
        int b2=i*k2;
        int b3=i*k3;
        //检查是否重复
        while (b1>0)
        {
            a[b1%10]++;
            b1/=10;
        }
        while (b2>0)
        {
            a[b2%10]++;
            b2/=10;
        }
        while (b3>0)
        {
            a[b3%10]++;
            b3/=10;
        }
        for (int j = 1; j <= 9; j++)
        {
            if (a[j]!=1)
            {
                alpha=true;
                break;
            }
        }
        //如果含有重复元素或者没用到1~9当中的任何一个，都应该不执行，由于上面的break只退出了最内层循环，因此此处需重置alpha
        if (alpha)
        {
            alpha=false;
        }
        else
        {
            sum++;
            cout<<i*k1<<" "<<i*k2<<" "<<i*k3<<endl;
        }
        //重置数组清零
        for (int j = 1; j <= 9; j++)
        {
            a[j]=0;
        }
    }
    if (sum==0)
    {
        cout<<"No!!!";
    }
}