#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>alls;
vector<pair<int,int>> add;
vector<pair<int,int>> query;
int a[301000],s[301000];
int find(int x)
{
    int l=0,r=alls.size()-1;
    while (l<r)
    {
        int mid=(l+r)/2;
        if(alls[mid]>=x)r=mid;
        else l=mid+1;
    }
    return r+1;
}
int main()
{
    int n,m,x,c,l,r;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>x>>c;
        alls.push_back(x);
        add.push_back({x, c});
    }
    for(int i=0;i<m;i++)
    {
        cin>>l>>r;
        alls.push_back(l);
        alls.push_back(r);
        query.push_back({l,r});
    }
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    for(auto item:add)
    {
        int x_map=find(item.first);
        a[x_map]+=item.second;
    }
    for (int i = 1; i <= alls.size(); i++)
    {
        s[i]=s[i-1]+a[i];
    }
    for(auto item:query)
    {
        int l_map=find(item.first);
        int r_map=find(item.second);
        cout<<s[r_map]-s[l_map-1]<<endl;
    }
}