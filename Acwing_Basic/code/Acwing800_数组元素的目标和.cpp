#include <iostream>

using namespace std;

const int N = 100010;
int n, m, x;
int a[N], b[N];

int main()
{
    cin >> n >> m >> x;
    for(int i = 0; i < n; i++)  scanf("%d", &a[i]);
    for(int i = 0; i < m; i++)  scanf("%d", &b[i]);
    int i = 0, j = m - 1;
    for(; i < n; i++)
    {
        //利用了a[i]在增大，b[j]一定会减小的单调性

        while(x < a[i] + b[j])  j--;
        
        if(a[i] + b[j] == x)    break;
        
    }
    cout << i << ' ' << j;
    return 0;
}
