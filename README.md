# 模板

[TOC]

## 1. 快速排序

在序列中取出某个位置的一个数`x`（这里选择中点），将小于`x`的放到序列左侧，大于`x`的放到序列右侧；对于左右两侧的序列再分别递归进行以上过程，直到序列只有一个元素为止（序列只有1个元素时天然有序；序列有2个元素时，经过程序后这个序列左边是较小值右边是较大值，完全有序了）

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

[AcWing 785. 快速排序](https://www.acwing.com/problem/content/787/)	

[AcWing 786. 第k个数](https://www.acwing.com/problem/content/788/)

## 2. 归并排序

