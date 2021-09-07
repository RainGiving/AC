#include <iostream>

using namespace std;

const int N = 1000010;

int n, k, hh, tt = -1;
int a[N], q[N];

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)	scanf("%d", &a[i]);
    //这一轮循环求的是每个窗口的最小值
    for(int i = 0; i < n; i++)
    {
        //注意单调队列中存放的是当前窗口的元素索引
        //判断当前队头是否还应在窗口中（a[i]入队时的队头应在i-k+1及其后）
        if(hh <= tt && q[hh] < i - k + 1)	hh++;
        //插入新队尾前先将无效的队内元素弹出
        while(hh <= tt && a[i] <= a[q[tt]])	tt--;
        //插入新队尾
        q[++tt] = i;
        //需要完整判断第一个窗口后再输出
        if(k - 1 <= i)	printf("%d ", a[q[hh]]);
    }
    cout << endl;
    
    hh = 0, tt = -1;
    //把弹出的无效元素修改为比a[i]小的元素，最后得到的a[q[hh]]就是每个窗口最大值
    for(int i = 0; i < n; i++)
    {
        if(hh <= tt && q[hh] < i - k + 1)   hh++;
        while(hh <= tt && a[q[tt]] <= a[i]) tt--;
        q[++tt] = i;
        if(k - 1 <= i)  printf("%d ", a[q[hh]]);
    }
    return 0;
}