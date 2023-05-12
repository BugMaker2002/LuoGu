#include <iostream>
using namespace std;
bool isPrime(int n)
{
    if (n==1)
    {
        return false;
    }
    if (n==2)
    {
        return true;
    }
    else
    {
        for (int i = 2; i*i <= n; i++)
        {
            if (n%i==0)
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int n;
    int a[102];
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        if (isPrime(a[i]))
        {
            cout<<a[i]<<" ";
        }
    }
    
}