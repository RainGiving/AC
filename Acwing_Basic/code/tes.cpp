#include <iostream>
#include <string>
using namespace std;

int n;

int main()
{
    cin >> n;
    getchar();
    while(n--)
    {
        string s;
        getline(cin, s);
        int P_index, T_index, cnt_p = 0, cnt_t = 0, cnt_a = 0;
        bool flag = true;
        
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'P')
            {
                P_index = i;	cnt_p++;
            }
            else if (s[i] == 'T')
            {
                T_index = i; 	cnt_t++;
            }
            else if(s[i] != 'A')
            {
                flag = false;
                break;
            }
            else    cnt_a++;
        }
        if(cnt_p != 1 || cnt_t != 1 || T_index < P_index || cnt_a == 0)	flag = false;
    
        int k1 = 0, k2 = 0, k3 = 0;
        k1 = P_index;
        k2 = T_index - P_index - 1;
        k3 = s.size() - T_index - 1;
        while(1 < k2)
        {
            k2--; k3 -= k1;
        }
        if(!(k1 == k3 && 0 <= k3))	flag = false;
        if(flag)    cout << "YES" << endl;
        else        cout << "NO" << endl;
    }
    return 0;
}