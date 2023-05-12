#include <iostream>
using namespace std;
int main()
{
    int n;
    int a,b,seq_a[202],seq_b[202],score_a=0,score_b=0;
    cin>>n>>a>>b;
    for (int i = 0; i < a; i++)
    {
        cin>>seq_a[i];
    }
    for (int i = 0; i < b; i++)
    {
        cin>>seq_b[i];
    }
    for (int i = 0; i < n; i++)
    {
        int s=seq_a[i%a];
        int t=seq_b[i%b];
        if (s==t)
        {
            continue;
        }
        if((s==0 && t==2)||(s==0 && t==3)||(s==1 && t==3)||(s==2 && t==4)||(s==3 && t==4)
        ||(s==1 && t==0)||(s==4 && t==0)||(s==2 && t==1)||(s==4 && t==1)||(s==3 && t==2))
        {
            score_a++;
        }
        else
        {
            score_b++;
        }
    }
    cout<<score_a<<" "<<score_b;
}