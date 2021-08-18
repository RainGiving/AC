#include <iostream>
using namespace std;

const int N = 100010;

int q[N], n, cnt;

bool check1(int mid, int k)   //bsearch1寻找左部右边界使用
{
    return q[mid] <= k;  //返回mid是否属于左部（以是否<=k区分左右）
}

bool check2(int mid, int k)   //bsearch2寻找右部左边界使用
{
    return !(q[mid] < k);    //返回mid是否属于右部（以是否<k区分左右）
}

int bsearch1(int l, int r, int k)
{
    while(l < r)
    {
        int mid = (l + r + 1) >> 1;
        if(check1(mid, k))  l = mid;
        else                r = mid - 1;
    }
    return (q[l] == k) ? l : -1;
}

int bsearch2(int l, int r, int k)
{
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(check2(mid, k))  r = mid;
        else                l = mid + 1;
    }
    return (q[l] == k) ? l : -1;
}


int main()
{
    cin >> n >> cnt;
    for(int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    while(cnt--)
    {
        int k;
        scanf("%d", &k);
        cout << bsearch2(0, n - 1, k) << ' ' << bsearch1(0, n - 1, k) << endl;
    }
    return 0;
}