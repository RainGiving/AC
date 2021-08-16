#include <iostream>

using namespace std;

const int N = 100010;

int n, q[N], k;

void quick_sort(int q[], int l, int r)
{
    if(r <= l)  return;
    int x = q[l + r >> 1], i = l - 1, j = r + 1;
    while(i < j)
    {
        do i++; while(q[i] < x);
        do j--; while(x < q[j]);
        if(i < j)   swap(q[i], q[j]);
    }
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    quick_sort(q, 0, n - 1);
    cout << q[k - 1];
    return 0;
}