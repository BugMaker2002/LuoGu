#include <iostream>
#include <cmath>
using namespace std;
int a[10000000]={0};
int main()
{
    int p,c=1;
    cin>>p;
    a[c]=1;
    for (int i = 0; i < p; i++)
    {
        int jw=0,j;
        for (j = 1; j <= min(c,500); j++)
        {
            int sum=a[j]*2+jw;
            a[j]=sum%10;
            jw=sum/10;
        }        
        if (c<=500)
        {
            while (jw>0)
            {
                a[j]=jw%10;
                jw/=10;
                j++;
            }
        }
        c=j-1;
    }  
    a[1]-=1;
    cout<<(int)(p*log10(2)+1)<<endl;
    for (int i = 500; i >= 1; i--)
    {
        printf("%d",a[i]);
        if ((501-i)%50==0)
        {
            printf("\n");
        }
    }
}