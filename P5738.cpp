#include <iostream>
#include <iomanip>
using namespace std;
double getAve(int m,int a[])
{
    double max=a[0];
    double min=a[0];
    double sum=0;
    for(int i=0;i<m;i++)
    {
        if(a[i]>max)
            max=a[i];
        if(a[i]<min)
            min=a[i];
        sum+=a[i];
    }
    return (sum-max-min)/(m-2);
}
int main()
{
    int n,m,a[22];
    double max=0,b[102]={0};
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>a[j];
        }
        b[i]=getAve(m,a);
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i]>max) 
        {
            max=b[i];
        }
    }
    cout<<fixed<<setprecision(2)<<max;
}