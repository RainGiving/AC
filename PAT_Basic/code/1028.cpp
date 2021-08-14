#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct People
{
    string name;
    int y;
    int m;
    int d;
} peo[100010];

bool cmp(struct People a, struct People b)
{
    if (a.y != b.y)
        return a.y < b.y;
    else if (a.m != b.m)
        return a.m < b.m;
    else
        return a.d < b.d;
}

int main()
{
    int n, cnt = 0;
    cin >> n;
    string tmp_name;
    int tmp_y, tmp_m, tmp_d;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp_name;
        scanf("%d/%d/%d", &tmp_y, &tmp_m, &tmp_d);
        if (tmp_y < 1814 || 2014 < tmp_y)
            continue;
        else if (tmp_y == 1814 && tmp_m < 9 || tmp_y == 2014 && 9 < tmp_m)
            continue;
        else if (tmp_y == 1814 && tmp_m == 9 && tmp_d < 6 || tmp_y == 2014 && tmp_m == 9 && 6 < tmp_d)
            continue;
        else
        {
            peo[cnt].name = tmp_name;
            peo[cnt].y = tmp_y;
            peo[cnt].m = tmp_m;
            peo[cnt].d = tmp_d;
            cnt++;
        }
    }
    sort(peo, peo + cnt, cmp);
    if (cnt == 0)
        cout << 0;
    else
        cout << cnt << " " << peo[0].name << " " << peo[cnt - 1].name;
    return 0;
}