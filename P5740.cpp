#include <iostream>
using namespace std;
int main()
{
    int n,x[1001],y[1001],z[1001],grade[1001];
    string name[1001];
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>name[i]>>x[i]>>y[i]>>z[i];
        grade[i]=x[i]+y[i]+z[i];
    }
    int max=0,index=0;
    for (int i = 0; i < n; i++)
    {
        if (grade[i]>max)
        {
            max=grade[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (grade[i]==max)
        {
            index=i;
            break;
        }
    }
    cout<<name[index]<<" "<<x[index]<<" "<<y[index]<<" "<<z[index];
}