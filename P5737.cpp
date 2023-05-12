#include <bits/stdc++.h>
using namespace std;
bool isYear(int year)
{
    if (year % 4 == 0 && year % 100!= 0 || year % 400 == 0)
        return true;
    else
        return false;
}
int main()
{
    int x,y,sum=0;
    cin>>x>>y;
    for (int i = x; i <= y; i++)
    {
        if (isYear(i))
        {
            sum++;
        }    
    }
    cout<<sum<<endl;
    for (int i = x; i <= y; i++)
    {
        if (isYear(i))
        {
            cout<<i<<" ";
        }    
    }
    
}