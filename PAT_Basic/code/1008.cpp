#include <iostream>
using namespace std;
int a[300], b[300];
int main()
{
    int n, m;
    cin >> n >> m;
    m = m % n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int j = 0;
    for (int i = n - m; i < n; i++)
        b[j++] = a[i];
    for (int i = 0; i < n - m; i++)
        b[j++] = a[i];
    for (int i = 0; i < n - 1; i++)
        cout << b[i] << ' ';
    cout << b[n - 1];
    return 0;
}