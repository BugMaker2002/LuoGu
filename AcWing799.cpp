#include <iostream>
using namespace std;
int a[100010];
int s[100010];
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int ans=1;
    for(int i=0, j=0; i<n; i++)
    {
        s[a[i]]++;
        while(s[a[i]]>1)
        {
            s[a[j]]--;
            j++;
        }
        ans=max(ans,i-j+1);
    }
    cout<<ans;
}