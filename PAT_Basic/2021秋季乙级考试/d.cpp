#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 11000000;

int hs[N];

int qs[10010];


int main()
{
    int n, k;   //允许开的数组数，用户访问次数
    cin >> n >> k;
    int cnt = -1, qscnt = 0;
    for(int i = 0; i < n; i++)
    {
        int head, len;
        cin >> head >> len;
        for(int j = head; j < head + len * 4; j += 4)
            hs[++cnt] = j;
        qs[++qscnt] = cnt;
    }
    int maxindex = -1;
    for(int i = 0; i < k; i++)
    {
        int index;
        cin >> index;
        if(cnt < index)    cout << "Illegal Access" << endl;
        else    
        {
            cout << hs[index] << endl;
            maxindex = max(maxindex, index);
        }
    }
    int res = 1;
    while(qs[res] < maxindex)
    res++;
    cout << res << endl;
    return 0;
}