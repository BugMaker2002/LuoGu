#include <iostream>
using namespace std;
int temp[5];
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
int main()
{
    int a[] = {9,4,2,4,1};
    merge_sort(a,0,4);
    for(int i = 0; i <5;i++)
    {
        cout<<a[i]<<endl;
    }
}