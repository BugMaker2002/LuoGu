#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
struct point
{
    int x;
    int y;
    int z;
}points[50004];
bool compare(point a,point b)
{
    return a.z<b.z;
}
int main()
{
    int n;
    double sum=0;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>points[i].x>>points[i].y>>points[i].z;
    }
    sort(points+1,points+1+n,compare);
    for (int i = 1; i <= n-1; i++)
    {
        double part=pow(pow(points[i].x-points[i+1].x,2)+
        pow(points[i].y-points[i+1].y,2)+
        pow(points[i].z-points[i+1].z,2)
        ,0.5);
        sum+=part;
    }
    cout<<fixed<<setprecision(3)<<sum;
}