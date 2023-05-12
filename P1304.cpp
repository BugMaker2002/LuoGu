#include <iostream>
using namespace std;
bool isPrime(int x)
{
    if (x == 1)
        return false;
    if (x == 2)
    {
        return true;
    }
    else
    {
        for (int i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
                return false;
        }
        return true;
    }
}
int main()
{
    int N;
    cin>>N;
    for(int i=4; i<=N; i+=2)
    {
        for (int j = 2; j <= i-2; j++)
        {
            if (isPrime(j)&&isPrime(i-j))
            {
                cout<<i<<"="<<j<<"+"<<i-j<<endl;
                break;
            }
            
        }
        
    }
}