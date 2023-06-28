#include <iostream>
using namespace std;
bool isPrime(int x)
{
    if(x < 2) return false;
    //判断条件最好不用写成i * i <= n，因为存在溢出风险
    for(int i = 2; i <= x / i; i++)
    {
        if(x % i == 0) return false;
    }
    return true;
}
int main()
{
    int n, a;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a;
        if(isPrime(a))
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    
}