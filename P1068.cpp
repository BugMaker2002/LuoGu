#include <iostream>
#include <algorithm>
using namespace std;
struct student
{
    int num;
    int grade;
}students[5005];
bool compare(student s1,student s2)
{
    if (s1.grade==s2.grade)
    {
        return s1.num<s2.num;
    }
    else
    {
        return s1.grade>s2.grade;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        cin>>students[i].num>>students[i].grade;
    }
    sort(students+1,students+n+1,compare);
    m=m*1.5;
    int sum=0;
    int grade_line=students[m].grade;
    for (int i = 1;i<=n; i++)
    {
        if (students[i].grade>=grade_line)
        {
            sum++;
        }   
    }
    cout<<grade_line<<" "<<sum<<endl;
    for (int i = 1;i<=n; i++)
    {
        if (students[i].grade>=grade_line)
        {
            cout<<students[i].num<<" "<<students[i].grade<<endl;
        }   
    }
}