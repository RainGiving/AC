#include <iostream>
using namespace std;
int n;

char themax(int c, int j, int b)
{
    if (c == j && j == b || b == c && j < b || b == j && c < b)
        return 'B';
    else if (c == j && b < c)
        return 'C';
    else if (c < j && b < j)
        return 'J';
    else if (c < b && j < b)
        return 'B';
    else if (j < c && b < c)
        return 'C';
}

//判断输赢，a赢返回1，b赢返回-1，平局返回0
int win(char a, char b)
{
    if (a == 'C')
    {
        if (b == 'J')
            return 1;
        else if (b == 'B')
            return -1;
        else
            return 0;
    }
    else if (a == 'J')
    {
        if (b == 'B')
            return 1;
        else if (b == 'C')
            return -1;
        else
            return 0;
    }
    else if (a == 'B')
    {
        if (b == 'C')
            return 1;
        else if (b == 'J')
            return -1;
        else
            return 0;
    }
}

int main()
{
    cin >> n;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    int win1c = 0, win1j = 0, win1b = 0, win2c = 0, win2j = 0, win2b = 0;
    while (n--)
    {
        char a, b;
        cin >> a >> b;
        if (0 < win(a, b))
        {
            cnt1++;
            if (a == 'C')
                win1c++;
            else if (a == 'J')
                win1j++;
            else if (a == 'B')
                win1b++;
        }
        else if (win(a, b) < 0)
        {
            cnt2++;
            if (b == 'C')
                win2c++;
            else if (b == 'J')
                win2j++;
            else if (b == 'B')
                win2b++;
        }
        else
            cnt3++;
    }

    cout << cnt1 << " " << cnt3 << " " << cnt2 << endl;
    cout << cnt2 << " " << cnt3 << " " << cnt1 << endl;
    cout << themax(win1c, win1j, win1b) << " " << themax(win2c, win2j, win2b);
    return 0;
}