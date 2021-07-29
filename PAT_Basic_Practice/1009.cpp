#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack<string> ss;
    string str;
    while (cin >> str)
        ss.push(str);

    while (!ss.empty() && 1 < ss.size())
    {
        cout << ss.top() << " ";
        ss.pop();
    }
    cout << ss.top();
    ss.pop();
    return 0;
}