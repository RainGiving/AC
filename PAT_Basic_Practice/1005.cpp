#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    int data;
    bool is = true; //是否是关键值
} a[105];
int n;
int find(int x)
{
    for (int i = 0; i < n; i++)
        if (a[i].data == x)
            return i;
    return -1;
}
bool cmp(struct node a, struct node b)
{
    return b.data < a.data; //使用sort从大到小排列
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].data;
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
    {
        int cnt = 5000, tmp = a[i].data;
        while (cnt--)
        {
            if (tmp % 2 == 0)
                tmp /= 2;
            else
                tmp = (3 * tmp + 1) / 2;
            if (find(tmp) == -1)
                continue;
            else
                a[find(tmp)].is = false;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (a[i].is)
            cnt++;
    for (int i = 0; i < n; i++)
        if (a[i].is && 1 < cnt)
        {
            cout << a[i].data << ' ';
            cnt--;
        }
        else if (a[i].is && cnt == 1)
            cout << a[i].data;
    return 0;
}