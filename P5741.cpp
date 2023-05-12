#include <iostream>
using namespace std;
int main()
{
    int n,x[1002],y[1002],z[1002];
    string name[1002];
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>name[i]>>x[i]>>y[i]>>z[i];
    }
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (abs(x[i]-x[j])<=5 && abs(y[i]-y[j])<=5 && abs(z[i]-z[j])<=5 && abs(x[i]+y[i]+z[i]-x[j]-y[j]-z[j])<=10)
            {
                cout<<name[i]<<" "<<name[j]<<endl;
            }
        }
    }
}