#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 110;

map<int, vector<PII>> m;

void make()
{
    for(int i = 1; i < N; i++)
    {
        for(int j = i + 1; j < N; j++)
        {
            m[i * i + i * j + j * j].push_back({i, j});
        }
    }
}



int main()
{
    int n;
    cin >> n;
    make();
    for(int i = 0; i < n; i++)
    {
        int num;
        bool flag = true;
        cin >> num;
        while(m[num].size() < 1)   
        {
            num++;
            flag = false;
        }
        if(flag)    cout << "Yes" << endl;
        else        cout << "No" << " " << num << endl;
        for(int i = 0; i < m[num].size(); i++)
        {
            cout << m[num][i].first << " " << m[num][i].second << endl;
        }
    }
    // for(auto iter = m.begin(); iter != m.end(); iter++)
    // {
    //     for(int i = 0; i < iter->second.size(); i++)
    //     {
    //         cout << iter->first << " " << iter->second[i].first << " " << iter->second[i].second << endl;
    //     }
    // }
    return 0;
}