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
    for(int i = 0; i < op.size(); i++)
    {
        if(op[i] == '0')    //a在此处的字符不变
        {
            tmp.push_back(a[i]);
        }
        else if(op[i] == '1') //a在此处的字符被删除
        ;  
        else if(op[i] == '2')//a在此处的字符被修改
        {
            tmp.push_back('*');
        }
        else 
            return false;
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
        string op;  //用户对字符串对应位置的操作
        getchar();
        getline(cin, op);
        bool flag = true;
        int cnt = 0;
        for(int i = 0; i < op.size(); i++)
        {
            if(!('0' <= op[i] && op[i] <= '3'))
            {
                flag = false;   break;
            }
            else if(op[i] != '0')   cnt++;
        }
        if(flag && check(op) && cnt == k)   cout << "AC" << endl;
        else                    cout << "WA" << endl;
    }
    return 0;
}