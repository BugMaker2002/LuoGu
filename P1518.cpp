#include <iostream>
using namespace std;
int zt[800005]={0};
int main()
{
    char land[12][12];
    
    // direction表示方向，0北，1东，2南，3西
    int time=0,x,y,a,b,direction1=0,direction2=0;
    // 布置padding，即将边界那块也设为'*'
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j  < 12; j++)
        {
            land[i][j]='*';
        }
    }
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            cin>>land[i][j];
            if (land[i][j]=='C')
            {
                x=i;
                y=j;
            }
            else if (land[i][j]=='F')
            {
                a=i;
                b=j;
            }
        }
    }
    while (true)
    {
        if (direction1==0)
        {
            if (land[x-1][y]!='*')
            {
                x--;
            }
            else
            {
                direction1=(direction1+1)%4;
            }
        }
        else if (direction1==1)
        {
            if (land[x][y+1]!='*')
            {
                y++;
            }
            else
            {
                direction1=(direction1+1)%4;
            }
        }
        else if (direction1==2)
        {
            if (land[x+1][y]!='*')
            {
                x++;
            }
            else
            {
                direction1=(direction1+1)%4;
            }
        }
        else if (direction1==3)
        {
            if (land[x][y-1]!='*')
            {
                y--;
            }
            else
            {
                direction1=(direction1+1)%4;
            }
        }
        if (direction2==0){
            if (land[a-1][b]!='*')
            {
                a--;
            }
            else
            {
                direction2=(direction2+1)%4;
            }
        }
        else if (direction2==1){
            if (land[a][b+1]!='*')
            {
                b++;
            }
            else
            {
                direction2=(direction2+1)%4;
            }
        }
        else if (direction2==2){
            if (land[a+1][b]!='*')
            {
                a++;
            }
            else
            {
                direction2=(direction2+1)%4;
            }
        }
        else if (direction2==3){
            if (land[a][b-1]!='*')
            {
                b--;
            }
            else
            {
                direction2=(direction2+1)%4;
            }
        }
        time++;
        if (x==a && y==b)
        {
            break;
        }
        //如果再次进入了该状态说明陷入了死循环，应该退出
        int k=x+y*10+a*100+b*1000+direction1*10000+direction2*40000;
        if (zt[k])
        {
            time=0;
            break;
        }     
        zt[k]=1;
    }
    cout<<time;
}