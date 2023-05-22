#include <iostream>
using namespace std;
int main()
{
    long long n,m,sqr=0,rec=0;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i==j)
            {
                sqr+=(n-i)*(m-j);
            }
            else
            {
                rec+=(n-i)*(m-j);
            }
        }
    }
    cout<<sqr<<" "<<rec;
}