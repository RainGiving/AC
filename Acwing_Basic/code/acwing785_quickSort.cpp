#include <iostream>
using namespace std;

const int N = 100010;
int q[N], n;

void quick_sort(int q[], int l, int r)
{
    if(r <= l)	return;	//递归基，r == l说明要排序的序列只有一个元素，自然不用操作
    //因为后面我们让i,j先走一步才开始比较，所以这里i向前退一步，j向后退一步
    int x = q[l + r >> 1], i = i - 1, j = j + 1;	
    while(i < j)
    {
        do i++;	while(q[i] < x);	//找到一个q[i] >= x为止
        do j--; while(x < q[j]);	//找到一个q[j] <= x为止
        if(i < j) swap(q[i], q[j]);	//交换q[i], q[j]的值，以达成左侧均小于x右侧均大于x
    }
    //交换完成后，左侧就是l~j，右侧就是j+1~r，对这两部分继续以上过程
    quick_sort(q, l, j), quick_sort(q, j + 1, r);	
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)  scanf("%d", &q[i]);
    quick_sort(q, 0, n - 1);
    for(int i = 0; i < n; i++)  printf("%d ", q[i]);
    return 0;
}