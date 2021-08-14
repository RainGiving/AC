#include <iostream>
using namespace std;

int main()
{
    int e, c;
    cin >> c >> e;
    if (e == 0)
        cout << 0 << " " << 0;
    else
    {
        c = e * c;
        e = e - 1;
        cout << c << " " << e;
    }

    while (cin >> c >> e)
    {
        if (e != 0)
        {
            c = e * c;
            e = e - 1;
            cout << " " << c << " " << e;
        }
    }
    return 0;
}