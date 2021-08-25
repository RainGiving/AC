#include <iostream>
using namespace std;

const int N = 100010;

int q[N], n, cnt;

int bsearch1(int l, int r, int k)
{
    while(l < r)
    {
        int mid = (l + r + 1) >> 1;
        if(q[mid] <= k) l = mid;
        else            r = mid - 1;
    }
    return q[r] == k ? r : -1;
}

int bsearch2(int l, int r, int k)
{
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(k <= q[mid]) r = mid;
        else            l = mid + 1;
    }
    return q[r] == k ? r : -1;
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