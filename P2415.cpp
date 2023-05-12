#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[31],b[35][35]={0};
    b[1][1]=1;
    int i=0;
    long long sum=0,sum_index=0;
    for (int k = 2; k <= 30; k++)
    {
        for(int s=1;s<=30;s++)
        {
            b[k][s]=b[k-1][s]+b[k-1][s-1];
        }
    }
    while(cin>>a[i])
    {
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        sum+=a[j];
        sum_index+=b[i][j+1];
    }
    // cout<<sum<<endl;
    // cout<<sum_index<<endl;
    long long x=0;
    x=sum*sum_index;
    cout<<(long long)x;
}