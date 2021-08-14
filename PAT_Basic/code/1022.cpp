#include <iostream>
#include <stack>
using namespace std;

void tenToD(long long c, long long d)
{
    stack<int> s;
    if (c == 0)
    {
        cout << 0;
        return;
    }
    while (0 < c)
    {
        s.push(c % d);
        c /= d;
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}

long long a, b, c, d;
int main()
{
    cin >> a >> b >> d;
    c = a + b;
    tenToD(c, d);
}
