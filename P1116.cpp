#include <iostream>
using namespace std;
int a[10005];
int main()
{
    int n,sum=0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    /**
     * @brief 
     * 对于每个数，只要它前面有比它大的数，就算做一次移动
     */
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i]<a[j])
            {
                sum++;
            }
        }
    }
    cout<<sum;
}