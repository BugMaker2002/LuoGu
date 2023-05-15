#include <iostream>
#include <algorithm>
using namespace std;
struct student
{
    int num;
    string name;
    int year;
    int month;
    int day;
}students[102];
bool compare(student x,student y)
{
    if (x.year!=y.year)
    {
        return x.year<y.year;
    }
    else
    {
        if (x.month!=y.month)
        {
            return x.month<y.month;
        }
        else
        {
            if (x.day!=y.day)
            {
                return x.day<y.day;
            }
            else
            {
                return x.num>y.num;
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>students[i].name>>students[i].year>>students[i].month>>students[i].day;
        students[i].num=i;
    }
    sort(students+1,students+1+n,compare);
    for (int i = 1; i <= n; i++)
    {
        cout<<students[i].name<<endl;
    }
}