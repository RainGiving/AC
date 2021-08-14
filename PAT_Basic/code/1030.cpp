#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll n, p, num[100005];

int main()
{
    cin >> n >> p;
    for (int i = 0; i < n; i++)
        cin >> num[i];

    sort(num, num + n);
    int Max = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + Max; j < n; j++)
            if (num[j] <= num[i] * p)
                Max = max(Max, j - i + 1);
            else
                break;

    cout << Max << endl;
    return 0;
}