#include <iostream>
using namespace std;
void divide(int x)
{
    for(int i = 2; i <= x / i; i++)
    {
        //不用判断i是不是质数，原因自己想想就明白了
        if(x % i == 0)
        {
            int s = 0;
            while(x % i == 0)
            {
                x /= i;
                s++;
            }
            cout<<i<<" "<<s<<endl;
        }
    }
    if(x > 1)
    {
        cout<<x<<" "<<1<<endl;
    }
}
int main()
{
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        divide(a);
        cout<<endl;
    }
}