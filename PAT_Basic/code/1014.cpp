#include <iostream>
#include <string>
using namespace std;
string s1, s2, s3, s4;

int main()
{
    cin >> s1 >> s2 >> s3 >> s4;
    char week, clock, minute;
    bool flag = false;
    for (int i = 0; i < min(s1.size(), s2.size()); i++)
    {
        if (s1[i] == s2[i] && flag == false && 0 <= s1[i] - 'A' && s1[i] - 'G' <= 0) // A ~ G
        {
            week = s1[i];
            flag = true;
            i++;
        }
        if (s1[i] == s2[i] && flag && (0 <= s1[i] - 'A' && s1[i] - 'N' <= 0 || 0 <= s1[i] - '0' && s1[i] - '0' <= 9)) // 0 ~ 9  A ~ N
        {
            clock = s1[i];
            break;
        }
    }
    for (int i = 0; i < min(s3.size(), s4.size()); i++)
    {
        if (s3[i] == s4[i] && (0 <= s3[i] - 'A' && s3[i] - 'Z' <= 0 || 0 <= s3[i] - 'a' && s3[i] - 'z' <= 0))
        {
            minute = i;
            break;
        }
    }
    if (week == 'A')
        cout << "MON";
    else if (week == 'B')
        cout << "TUE";
    else if (week == 'C')
        cout << "WED";
    else if (week == 'D')
        cout << "THU";
    else if (week == 'E')
        cout << "FRI";
    else if (week == 'F')
        cout << "SAT";
    else if (week == 'G')
        cout << "SUN";

    if (0 <= clock - '0' && clock - '0' <= 9)
        printf(" %02d", clock - '0');
    else
        printf(" %d", clock - 'A' + 10);
    printf(":%02d", minute);
    return 0;
}