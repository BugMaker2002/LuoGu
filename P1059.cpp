#include <iostream>
#include <algorithm>
using namespace std;
int a[102];
int b[102];
int main()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int index=1;
    b[0]=a[0];
    for (int i = 1; i < n; i++)
    {
        if (b[index-1]!=a[i])
        {
            b[index]=a[i];
            index++;
        }     
    }
    cout<<index<<endl;
    for (int i = 0; i < index; i++)
    {
        cout<<b[i]<<" ";
    }  
}