#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void merge(vector<pair<int,int>>& segs)
{
    vector<pair<int,int>> res;
    //按左端点大小排序
    sort(segs.begin(), segs.end());
    int st=-2e9,ed=-2e9;
    for(auto seg:segs)
    {
        if(ed<seg.first)
        {
            if(st!=-2e9)
            {
                res.push_back({st,ed});
            }
            st=seg.first;
            ed=seg.second;
        }
        else
        {
            ed=max(ed,seg.second);
        }
    }
    if(st!=-2e9)
    {
        res.push_back({st,ed});
    }
    segs=res;
}
int main()
{
    vector<pair<int,int>> segs;
    int n,l,r;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>l>>r;
        segs.push_back({l,r});
    }
    merge(segs);
    cout<<segs.size()<<endl;
}