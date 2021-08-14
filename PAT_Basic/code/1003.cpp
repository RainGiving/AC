#include <iostream>
#include <string>
using namespace std;

bool test(int a, int b, int c)
{
    if (b == 1 && a == c)
        return true;
    else if (b == 1)
        return false;
    if (test(a, b - 1, c - a))
        return true;
    else
        return false;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        bool flag = true;
        cin >> s;
        int P_index = -1, T_index = -1;
        //先找P和T的位置
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'P')
                P_index = i;
            else if (s[i] == 'T')
                T_index = i;
        }
        //没有P或T，或者P在T后面，错误
        if (P_index < 0 || T_index < 0 || T_index < P_index)
            flag = false;
        //统计P前面，P和T之间，T之后的A数量
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (i == P_index || i == T_index)
                continue;
            else if (s[i] != 'A')
            {
                flag = false;
                break;
            }
            else if (i < P_index)
                cnt1++;
            else if (P_index < i && i < T_index)
                cnt2++;
            else if (T_index < i)
                cnt3++;
        }
        if (!flag || cnt2 < 1)
        {
            cout << "NO" << endl;
            continue;
        }
        if (test(cnt1, cnt2, cnt3))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}