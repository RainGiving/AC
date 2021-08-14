#include <iostream>
using namespace std;
int table[1000];

void make_table()
{
    table[1] = 1;
    int new_flood = 3;
    for (int i = 2; i < 1000; i++)
    {
        table[i] = table[i - 1] + 2 * new_flood;
        new_flood += 2;
    }
}

int main()
{
    make_table();
    int num;
    char sign;
    cin >> num >> sign;
    int cnt = 0;
    while (true)
        if (num < table[++cnt])
            break;
    cnt--;
    for (int j = cnt; 0 < j; j--)
    {
        int charnum = 1 + 2 * (j - 1), spacenum = 1 + 2 * (cnt - 1) - charnum;
        for (int k = 0; k < spacenum / 2; k++)
            cout << " ";
        for (int k = 0; k < charnum; k++)
            cout << sign;
        cout << endl;
    }
    for (int j = 2; j <= cnt; j++)
    {
        int charnum = 1 + 2 * (j - 1), spacenum = 1 + 2 * (cnt - 1) - charnum;
        for (int k = 0; k < spacenum / 2; k++)
            cout << " ";
        for (int k = 0; k < charnum; k++)
            cout << sign;
        cout << endl;
    }
    cout << num - table[cnt];
    return 0;
}