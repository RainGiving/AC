#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s1, s2;
vector<char> bad;

bool check(char c, vector<char> vc)
{
    for (int i = 0; i < vc.size(); i++)
    {
        if (c == vc[i] || ('a' <= c && c <= 'z' && c - ('a' - 'A') == vc[i]))
            return false;
    }
    return true;
}

int main()
{
    getline(cin, s1);
    getline(cin, s2);
    int i = 0, j = 0;
    while (i < s1.size())
    {
        if (s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            if (check(s1[i], bad))
            {
                if ('a' <= s1[i] && s1[i] <= 'z')
                    bad.push_back(s1[i] - ('a' - 'A'));
                else
                    bad.push_back(s1[i]);
            }
            i++;
        }
    }
    for (int i = 0; i < bad.size(); i++)
        cout << bad[i];
    return 0;
}