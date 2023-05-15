#include <iostream>
#include <algorithm>
using namespace std;      
struct student
{
    int num;
    int grade1;
    int grade2;
    int grade3;
}students[303];
bool compare(student s1,student s2)
{
    if (s1.grade1+s1.grade2+s1.grade3==s2.grade1+s2.grade2+s2.grade3)
    {
        if (s1.grade1==s2.grade1)
        {
            return s1.num<s2.num;
        }
        else
        {
            return s1.grade1>s2.grade1;
        }
    }
    else
    {
        return s1.grade1+s1.grade2+s1.grade3>s2.grade1+s2.grade2+s2.grade3;
    }
}
int main()
{
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>students[i].grade1>>students[i].grade2>>students[i].grade3;
        students[i].num=i;
    }
    sort(students+1,students+n+1,compare);
    for (int i = 1; i <= min(n,5); i++)
    {
        cout<<students[i].num<<" "<<students[i].grade1+students[i].grade2+students[i].grade3<<endl;
    }
}