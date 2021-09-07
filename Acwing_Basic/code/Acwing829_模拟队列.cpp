#include <iostream>
#include <string>

using namespace std;

const int N = 100010;

int n, q[N], hh, tt = -1;

int main()
{
    cin >> n;
    while(n--)
    {
        string op;
        int x;
        cin >> op;
        if(op == "push")
        {
            cin >> x;
            q[++tt] = x;
        }
        else if(op == "pop")    hh++;
        else if(op == "empty")
            if(hh <= tt)    cout << "NO" << endl;
            else cout << "YES" << endl;
        else if(op == "query")
            cout << q[hh] << endl;
    }
    return 0;
}