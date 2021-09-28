#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int N = 10000010;

int mp[N];

int mul(int num)
{
    int res = 1;
    while(0 < num)
    {
        res *= num % 10;
        num /= 10;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        mp[mul(num)]++;
    }
    int maxSize = 0, resmul = 0, resSize = 0;
    for(int i = 0; i < N; i++)
    {
        if(mp[i] != 0)  resSize++;

        if(maxSize < mp[i]) 
        {
            maxSize = mp[i];
            resmul = i;
        }
    }
    cout << resSize << " " << resmul << endl;
    return 0;
}
