# 二分
### 有单调性一定可以二分，没有单调性也有可能可以二分
## 整数二分
```cpp
bool check(int x) {/* ... */} // 检查x是否满足某种性质
// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
int bsearch1(int l, int r)
{
    while(l < r)
    {
        int mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    //由于l==r，return谁都可以
    return r;
}
// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
int bsearch2(int l, int r)
{
    while(l < r)
    {
        int mid = (l + r + 1) / 2;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    //由于l==r，return谁都可以
    return r;
}
```
## 浮点数二分
### 浮点数二分比整数二分要简单不少，因为不用考虑两种情况
```cpp
int bsearch(double l, double r)
{
    while(r - l > 1e-6)
    {
        double mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    return r;
}
```