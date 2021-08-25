#include <iostream>

using namespace std;

const int N = 100010;
int q[N], tmp[N], n;

void merge_sort(int q[], int l, int r)
{
    if(r <= l)	return;//只有一个元素，递归基
    int mid = (l + r) >> 1;
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);	//左右两边分别排序达到有序
    int k = 0, i = 1, j = mid + 1;	//i是左边部分起点，j是右边部分起点
    while(i <= mid && j <= r)
        if(q[i] <= q[j]) tmp[k++] = q[i++];	//q[i]较小，则把q[i]放到tmp后面
    	else 			 tmp[k++] = q[j++];	//同理
    while(i <= mid) tmp[k++] = q[i++];	//如果左边部分没有全部放入tmp，则直接依次放到tmp后边
    while(j <= r) 	tmp[k++] = q[j++];	//同理
    for(int i = l, j = 0; i <= r; ++i, ++j)
        q[i] = tmp[j];	//把tmp依次放回q
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)  scanf("%d", &q[i]);
    merge_sort(q, 0, n - 1);
    for(int i = 0; i < n; i++)  printf("%d ", q[i]);
    return 0;
}