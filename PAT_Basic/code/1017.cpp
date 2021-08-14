#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a;
    int b;
    cin >> a >> b;
    int cur = a[0] - '0', bef = 0;
    if (cur < b && a.size() == 1)
    {
        cout << 0;
        bef = cur * 10;
    }
    else if (cur < b)
        bef = cur * 10;
    else
    {
        cout << cur / b;
        bef = (cur - (cur / b) * b) * 10;
    }
    for (int i = 1; i < a.size(); i++)
    {
        cur = a[i] - '0' + bef;
        if (cur < b)
        {
            cout << 0;
            bef = cur * 10;
        }
        else
        {
            cout << cur / b;
            bef = (cur - (cur / b) * b) * 10;
        }
    }
    cout << " " << bef / 10;
    return 0;
}