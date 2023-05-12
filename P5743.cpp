#include <iostream>
using namespace std;
int main()
{
    int n,y=1;
    cin>>n;
    for(int i=1; i<=n-1; i++)
    {
        y=2*y+2;
    }
    cout<<y;
}