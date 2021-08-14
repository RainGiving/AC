# 模板

[TOC]

## 1. 快速排序

在数组中取出某个位置的一个数`x`（这里选择中点），将小于`x`的放到数组左侧，大于`x`的放到数组右侧；对于左右两侧的数组再分别递归进行以上过程，直到数组只有一个元素为止（数组只有1个元素时天然有序；数组有2个元素时，经过程序后这个数组左边是较小值右边是较大值，完全有序了）

```cpp
void quick_sort(int q[], int l, int r)
{
    if(r <= l)	return;	//递归基，r == l说明要排序的序列只有一个元素，自然不用操作
    int x = q[(l + r) >> 1], i = i - 1, j = j + 1;	//因为后面我们让i,j先走一步才开始比较，所以这里i向前退一步，j向后退一步
    while(i < j)
    {
        do i++;	while(q[i] < x);	//找到一个q[i] >= x为止
        do j--; while(x < q[j]);	//找到一个q[j] <= x为止
        if(i < j) swap(q[i], q[j]);	//交换q[i], q[j]的值，以达成左侧均小于x右侧均大于x
    }
    quick_sort(q, l, j), quick_sort(q, j + 1, r);	//交换完成后，左侧就是l~j，右侧就是j+1~r，对这两部分继续以上过程
}
```

[AcWing 785. 快速排序](https://www.acwing.com/problem/content/787/)----------[AC代码](https://github.com/RainGiving/AC/blob/master/Acwing_Basic/code/acwing785_quickSort.cpp)

[AcWing 786. 第k个数](https://www.acwing.com/problem/content/788/)

## 2. 归并排序

确定数组的中点为分界点，递归对左右两部分进行归并排序，两边排序完成后再将两部分合并（当左右两边各有一个元素时左右两部分天然有序，此时直接对这两个元素合并即可）

```cpp
int tmp[N];	//临时存放合并得到数组
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
```

[AcWing 787. 归并排序](https://www.acwing.com/problem/content/789/)

[AcWing 788. 逆序对的数量](https://www.acwing.com/problem/content/790/)

