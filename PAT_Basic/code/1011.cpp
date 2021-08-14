#include <iostream>
using namespace std;
#define ll long long

int main()
{
    ll a, b, c, T;
    cin >> T;
    int i = 0;
    while (T--)
    {
        cin >> a >> b >> c;
        cout << "Case #" << ++i << ": ";
        if (a - c > -b)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}