#include <iostream>
using namespace std;
int S[1010][1010]={0},a[1010][1010]={0};
int main()
{
    int n,m,q,x1,y1,x2,y2,c;
    cin>>n>>m>>q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin>>S[i][j];
            a[i][j] = S[i][j]-S[i-1][j]-S[i][j-1]+S[i-1][j-1];
        }
    }
    while (q-->0)
    {
        cin>>x1>>y1>>x2>>y2>>c;
        a[x1][y1]+=c;
        a[x1][y2+1]-=c;
        a[x2+1][y1]-=c;
        a[x2+1][y2+1]+=c;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            S[i][j]=S[i-1][j]+S[i][j-1]+a[i][j]-S[i-1][j-1];
            cout<<S[i][j]<<" ";
        }
        cout<<endl;
    }
}