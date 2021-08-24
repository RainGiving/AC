#include <iostream>

using namespace std;

const int N = 100010;

int n, m;

int a[N], b[N];

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)  scanf("%d", a + i);
    for(int i = 0; i < m; i++)  scanf("%d", b + i);
    int i = 0;
    for(int j = 0; j < m; j++)
        if(a[i] == b[j])    i++;
        
    if(n <= i)  cout << "Yes" << endl;
    else        cout << "No" << endl;
    return 0;
}