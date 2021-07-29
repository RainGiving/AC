#include <iostream>
using namespace std;
const int N = 100010;
int q[N];
int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        scanf("%d", &q[i]);
    while (m--)
    {
        int k;
        cin >> k;
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (k <= q[mid])
                r = mid;
            else
                l = mid + 1;
        }
        if (q[l] != k)
            cout << -1 << ' ';
        else
            cout << l << ' ';

        l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (q[mid] <= k)
                l = mid;
            else
                r = mid - 1;
        }
        if (q[l] != k)
            cout << -1 << endl;
        else
            cout << l << endl;
    }
    return 0;
}