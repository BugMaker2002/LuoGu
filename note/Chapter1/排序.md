# 快速排序
### 主要思想：基于**分治**实现
### 步骤：
### 1.确定分界点
### 2.调整区间
### 3.递归处理左右两端
## 代码模板：
```cpp
void quick_sort(int q[], int l, int r)
{
    if(l >= r) return;
    int x = q[l], i = l - 1, j = r + 1;
    while(i < j)
    {
        do i ++ ; while(q[i] < x);
        do j -- ; while(q[j] > x);
        if(i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}
```

# 归并排序
### 主要思想：基于**分治**实现
### 步骤
### 1.递归排序左右边
### 2.归并，合二为一
## 代码模板：
```cpp
const int N = 100;
int q[N], temp[N];
void merge_sort(int q[], int l, int r)
{
    if(l >= r) return;
    int mid = (l + r) / 2;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r)
    {
        if(q[i] <= q[j])
            temp[k++] = q[i++];
        else
            temp[k++] = q[j++];
    }
    while(i <= mid) temp[k++] = q[i++];
    while(j <= r) temp[k++] = q[j++];
    for(i = l, k = 0; i <= r; i++, k++)
        q[i] = temp[k];
}
```