# Acwing788_逆序对的数量

题目地址：https://www.acwing.com/problem/content/790/

给定一个长度为 `n` 的整数数列，请你计算数列中的逆序对的数量。

逆序对的定义如下：对于数列的第 `i` 个和第 `j` 个元素，如果满足 `i < j` 且 `a[i] > a[j]`，则其为一个逆序对；否则不是。

#### 输入格式

第一行包含整数 `n`，表示数列的长度。

第二行包含 `n` 个整数，表示整个数列。

#### 输出格式

输出一个整数，表示逆序对的个数。

#### 数据范围

`1 ≤ n ≤ 1e5`
数列中的元素的取值范围 `1 ~ 1e9`。

#### 输入样例：

```input
6
2 3 4 5 6 1
```

#### 输出样例：

```output
5
```

我们用归并排序的思路处理这个问题，当已经确定了`mid`将这个数组划分为`[l, mid]`和`[mid + 1,  r]`两部分时，这个数组中存在的逆序对数就是 左边部分的逆序对数 + 右边部分的逆序对数 + 跨越左右两部分的逆序对数，如图所示![image-20210816101538181](https://raw.githubusercontent.com/RainGiving/PictureBed/master/img1/20210816101538.png)

我们递归处理这个问题，函数`int merge_sort(int q[], int l, int r)`返回`[l, r]`区间的逆序对数量，因此，左部逆序对数量通过`merge_sort(q, l, mid)`求得，右部逆序对数量`merge_sort(q, mid + 1, r)`求得，我们只需要求**跨越边界的逆序对数量**即可

```cpp
ll merge_sort(int q[], int l, int r)
{
    ll res = 0;
    int mid = l + r >> 1;
    res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
    //求跨越边界的逆序对数量
    ...
    return res;
}
```

此时左部数组和右部数组均已有序，当有左部数组中的`q[i]`大于右部数组中的`q[j]`时，`q[i] ~ q[mid]`共`mid - i + 1`个元素和`q[j]`组成了`mid - i + 1`个逆序对，将其累加到逆序对总数上即可

另外，1e5大小的数组可以构成的最大逆序对数量在`int`数据范围外，`res`需要使用`long long`定义

```cpp
#include<iostream>
using namespace std;
typedef long long ll;
const int N = 100010;
int q[N], n, tmp[N];

ll merge_sort(int q[], int l, int r)
{
    if(r <= l)  return  0;	//递归基
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
    cin >> n;
    for(int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    cout << merge_sort(q, 0, n - 1);
    return 0;
}
```

