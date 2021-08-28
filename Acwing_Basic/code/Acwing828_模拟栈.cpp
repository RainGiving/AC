#include <iostream>
#include <string>
using namespace std;

const int N = 100010;

int stk[N], tt;
int m;

int main()
{
    cin >> m;
    while(m--)
    {
        string op;
        int x;
        cin >> op;
        if(op == "push")
        {
            cin >> x;
            stk[++tt] = x;
        }
        else if(op == "pop")    tt--;
        else if(op == "empty")
            if(0 < tt)   cout << "NO" << endl;
            else        cout << "YES" << endl;
        else if(op == "query")  cout << stk[tt] << endl;
            
    }
    return 0;
}