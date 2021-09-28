#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
string a, b;


bool check(string op)
{
    string tmpa = a, tmpb = b, tmp;
    bool res = true;
    for(int i = 0, j = 0; i < op.size(); i++)
    {
        if(op[i] == '0')
        {
            if(a[i] != b[j]) res = false;  
            else    j++;
        }
        else if(op[i] == '1')
            ;
        else if(op[i] == '2')
        {
            if(b.size() <= i)   b.push_back(a[i]);
            else                b[j] = a[i];
            j++;
        }
        else if(op[i] == '3')
        {
            if(b.size() <= i)   b.push_back(a[i]);
        }

    }



    if(b.size() != tmp.size())  return false;
    for(int i = 0; i < b.size(); i++)
    {
        if(tmp[i] != '*' && tmp[i] != b[i])
            return false;
    }
    return true;
}






int main()
{
    getline(cin, a);
    getline(cin, b);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int k;  //用户输出动作数
        cin >> k;
        if(k == 0)
        {
            if(a == b)  cout << "AC" << endl;
            else        cout << "WA" << endl;
            continue;
        }
        string op;  //用户对字符串对应位置的操作
        getchar();
        getline(cin, op);
        bool flag = true;

        int p0 = 0, p1 = 0, p2 = 0, p3 = 0;
        for(int i = 0; i < op.size(); i++)
        {
            if(!('0' <= op[i] && op[i] <= '3'))
            {
                flag = false;   break;
            }
            if(op[i] == '0')    p0++;
            else if(op[i] == '1')   p1++;
            else if(op[i] == '2')   p2++;
            else if(op[i] == '3')   p3++;
        }
        if(a.size() - p1 + p3 != b.size())  flag = false;
        if(flag)    
            if(check(op))   cout << "AC" << endl;
            else            cout << "WA" << endl;
        else                cout << "WA" << endl;

    }
    return 0;
}