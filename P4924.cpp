#include <iostream>
using namespace std;
int main()
{
    int n,m,a[502][502],b[502][502],x,y,r,z,index=1;
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j]=index;
            b[i][j]=index;
            index++;
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin>>x>>y>>r>>z;
        //顺时针旋转
        if (z==0)
        {
            for (int j = x - (2*r+1)/2; j <= x + (2*r+1)/2; j++)
            {
                for (int k = y - (2*r+1)/2; k <= y + (2*r+1)/2; k++)
                {
                    // cout<<"由（"<<j<<","<<k<<"）变到了（"<<k -(y - (2*r+1)/2)+x-(2*r+1)/2<<","<<x + (2*r+1)/2 - j + y - (2*r+1)/2<<")"<<endl;
                    b[k -(y - (2*r+1)/2)+x-(2*r+1)/2][x + (2*r+1)/2 - j + y - (2*r+1)/2]=a[j][k];
                }
            }
            for (int j = 1; j <= n; j++)
            {
                for (int k = 1; k <= n; k++)
                {
                    a[j][k]=b[j][k];
                }
            }
            
        }
        //逆时针旋转
        else
        {
            for (int j = x - (2*r+1)/2; j <= x + (2*r+1)/2; j++)
            {
                for (int k = y - (2*r+1)/2; k <= y + (2*r+1)/2; k++)
                {
                    b[(y + (2*r+1)/2)-k+x-(2*r+1)/2][j-(x - (2*r+1)/2) + y - (2*r+1)/2]=a[j][k];
                }
            }
            for (int j = 1; j <= n; j++)
            {
                for (int k = 1; k <= n; k++)
                {
                    a[j][k]=b[j][k];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    
}