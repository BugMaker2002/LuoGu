#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    double a[6];
    for (int i = 0; i < 6; i++)
    {
        cin >> a[i];
    }
    double x=pow((a[2]-a[0])*(a[2]-a[0])+(a[3]-a[1])*(a[3]-a[1]),0.5);
    double y=pow((a[4]-a[0])*(a[4]-a[0])+(a[5]-a[1])*(a[5]-a[1]),0.5);
    double z=pow((a[4]-a[2])*(a[4]-a[2])+(a[5]-a[3])*(a[5]-a[3]),0.5);
    cout<<fixed<<setprecision(2)<<x+y+z;
}