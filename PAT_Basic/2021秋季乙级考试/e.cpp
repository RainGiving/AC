#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int N = 10010;

int mz1[N], mz2[N], peo1[N], peo2[N], hs[1000010];

map<int, int> que;

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> mz1[i];  mz2[i] = mz1[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> peo1[i]; peo2[i] = peo1[i];
        hs[peo1[i]] = i;
    }
    sort(mz1 + 1, mz1 + n + 1);
    sort(peo1 + 1, peo1 + n + 1);
    for(int i = 1; i <= n; i++)
    {
        que[mz1[i]] = peo1[i];
    }

    for(int i = n; 1 < i; i--)
    {
        cout << hs[que[mz2[i]]] << " ";
    }
    cout << hs[que[mz2[1]]] << endl;
    return 0;
}