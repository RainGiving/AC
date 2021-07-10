#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int q[N];
int n;

void quick_sort(int q[], int l, int r)
{
    if (r <= l)
        return;
    int x = q[(l + r) / 2], i = l - 1, j = r + 1;
    while (i < j)
    {
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (x < q[j]);
        if (i < j)
            swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        scanf("%d", &q[i]);

    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n; ++i)
        cout << q[i] << ' ';
    return 0;
}