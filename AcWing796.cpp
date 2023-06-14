#include <iostream>
using namespace std;
int a[1010][1010],s[1010][1010];
int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    int x1,y1,x2,y2;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            //求前缀和
            s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    }
    while (q-->0)
    {
        cin>>x1>>y1>>x2>>y2;
        //算部分和
        cout<<s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]<<endl;
    }
}