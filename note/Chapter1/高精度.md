# 加法
### 存储方式：拿数组去存大数，数组开头存放低位数，往后依次存个位、十位、百位、千位等
## 代码模板：
```cpp
vector<int> add(vector<int> &A, vector<int> &B)
{
    if (A.size() < B.size())
        return add(B, A);
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i ++)
    {
        t += A[i];
        if(i < B.size())
            t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if(t)
        C.push_back(t);
    return C;
}
```
# 减法
## 代码模板：
```cpp
//我们先进行判断两个数的相对大小，然后采用一个模板进
//行运算，当小减大时，我们在前面输出一个负号即
//可(此处是判断字符串)
bool cmp(string s, string t) 
{
    if(s.length() != t.length())
    {
        return s.length() >= t.length();
    }
    else
    {
        return s >= t;
    }
}
//要求A表示的数必须大于B表示的数
vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    int t = 0;
    for(int i = 0; i < A.size(); i ++)
    {
        t = A[i] - t;
        if(i < B.size())
        {
            t = t - B[i];
        }
        C.push_back((t + 10) % 10);
        if(t >= 0)
        {
            t = 0;
        }
        else
        {
            t = 1;
        }
    }
    //解决9999-9991=9而非0009这种情况
    while(C.size() > 1 && C.back() == 0)
    {
        C.pop_back();
    }
    return C;
}
```
# 乘法
## 代码模板：
```cpp
vector<int> mul(vector<int>& A,int b)
{
    int t = 0;
    vector<int> C;
    for(int i = 0; i < A.size() || t; i++)
    {
        if(i < A.size())
            t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    //解决9999*0=0而非0000这种情况
    while(C.size() > 1 && C.back() == 0)
    {
        C.pop_back();
    }
    return C;
}
```
# 除法
## 代码模板：
```cpp
// A / b = C ... r, A >= 0, b > 0
//为了与上述例子统一，我们仍然将A倒序存放，按照除法的特殊
//性，此时我们需要从A的末尾开始循
//环求解（因为除法是从最高有效位开始的）
//A是被除数，b是除数，r是余数，返回结果C是商
vector<int> div(vector<int>A, int b, int & r)
{
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        r = r * 10 + A[i];
        C.push_back(r/b);
        r = r % b;
    }
    /**
     * 此时C当中存放的是正序存放的数，为了与之前的模板统
     * 一，我们需要将其倒放，并且去除七前导0，当然，为
     * 了方便，你也可以不倒放，并且判断条件
     * C.back() == 0改为
     * 判断C.font() == 0
     **/
    C.reverse(C.begin(), C.end());
    while(C.size() > 1 && C.back() == 0)
    {
        C.pop_back();
    }
    return C;
}
```