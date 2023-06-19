#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x,sum=0;
        cin>>x;
        while (x)
        {
            if(x&1)
            {
                sum++;
            }
            x=x>>1;
        }
        cout<<sum<<" ";
    }
}