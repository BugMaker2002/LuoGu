#include <iostream>
using namespace std;
struct node{
    int isOutside;
    string name;
}nodes[100002];
int main()
{
    int n,m,x,y;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        cin>>nodes[i].isOutside>>nodes[i].name;
    }
    int now=0;
    for (int i = 0; i < m; i++)
    {
        cin>>x>>y;
        if(x!=nodes[now].isOutside)
        {
            now=(now+y)%n;
        }
        else
        {
            now=(now+n-y)%n;
        }
    }
    cout<<nodes[now].name;
}