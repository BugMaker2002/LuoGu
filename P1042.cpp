#include <iostream>
#include <cmath>
using namespace std;
string sentence[2503];
int main()
{
    
    int index = 0;
    while (cin >> sentence[index])
    {
        index++;
    }
    /**
     * @brief 适用于EWLWLWL这种情况
     * 
     */
    if (sentence[0][0]=='E')
    {
        cout<<"0:0"<<endl<<endl<<"0:0";
        return 0;
    }
    /**
     * @brief 11分制的结果
     * 
     */
    int count1=0, win=0, loss=0;
    for (int i = 0; i < index; i++)
    {
        for(int j = 0; j < sentence[i].length(); j++)
        {
            if (sentence[i][j]=='E')
            {
                if (true)
                {
                    cout<<win<<":"<<loss<<endl;
                }
                break;
            }
            else
            {
                if(sentence[i][j]=='W')
                {
                    win++;
                    count1++;
                }
                else if (sentence[i][j]='L')
                {
                    loss++;
                    count1++;
                }
                
            }
            if((win>=11||loss>=11) && abs(win-loss)>=2)
            {
                cout<<win<<":"<<loss<<endl;
                count1=0;
                win=0;
                loss=0;
            }
        }
    }
    cout<<endl;
    /**
     * @brief 21分制的结果
     * 
     */
    count1=0;win=0;loss=0;
    for (int i = 0; i < index; i++)
    {
        for(int j = 0; j < sentence[i].length(); j++)
        {
            if (sentence[i][j]=='E')
            {
                if (true)
                {
                    cout<<win<<":"<<loss<<endl;
                }
                break;
            }
            else
            {
                if(sentence[i][j]=='W')
                {
                    // cout<<i<<"行"<<j<<"个为："<<sentence[i][j]<<endl;
                    win++;
                    count1++;
                }
                else if (sentence[i][j]='L')
                {
                    // cout<<i<<"行"<<j<<"个为："<<sentence[i][j]<<endl;
                    loss++;
                    count1++;
                }
                
            }
            if((win>=21||loss>=21) && abs(win-loss)>=2)
            {
                cout<<win<<":"<<loss<<endl;
                count1=0;
                win=0;
                loss=0;
            }
        }
    }
    
    

}