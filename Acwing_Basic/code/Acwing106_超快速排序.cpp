//交换相邻序列元素来达到有序的次数就是这个序列的逆序对数
//注意数据范围的变化做出修改即可


#include<iostream>
using namespace std;
typedef long long ll;
const int N = 500010;
ll q[N], n, tmp[N];

ll merge_sort(ll q[], int l, int r)
{
    if(r <= l)  return 0;	//递归基
    int mid = l + r >> 1;
    ll res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r)
        if(q[i] <= q[j])    tmp[k++] = q[i++];
        else
        {
            tmp[k++] = q[j++];
            res += mid - i + 1;
        }
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r)   tmp[k++] = q[j++];
    for(int i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j];
    return res;
}


int main()
{
    while(cin >> n, n != 0)
    {
        for(int i = 0; i < n; i++)
            scanf("%d", &q[i]);
        cout << merge_sort(q, 0, n - 1) << endl;
    }
    return 0;
}