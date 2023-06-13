#include <iostream>
#include <algorithm>
using namespace std;
int a[100010];
int b[100002];
unsigned long sum = 0;
void merge_sort(int a[], int l, int r)
{
    if(l >= r) return;
    int mid = (l + r) / 2;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r)
    {
        if(a[i] <= a[j]) b[k++] = a[i++];
        else 
        {
            sum+=(mid - i + 1);
            b[k++] = a[j++];
        }
    }
    while(i <= mid) b[k++] = a[i++];
    while(j <= r) b[k++] = a[j++];
    for (i = l, k = 0; i <= r; i++, k++)
    {
        a[i] = b[k];
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    merge_sort(a, 0, n-1);
    // for(int i = 0; i < n; i++)
    // {
    //     printf("%d ", a[i]);
    // }
    cout<<sum;
}