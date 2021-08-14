#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int downsort(int a1, int a2, int a3, int a4)
{
    int tmp[4] = {a1, a2, a3, a4};
    sort(tmp, tmp + 4);
    return tmp[0] + tmp[1] * 10 + tmp[2] * 100 + tmp[3] * 1000;
}

int upsort(int a1, int a2, int a3, int a4)
{
    int tmp[4] = {a1, a2, a3, a4};
    sort(tmp, tmp + 4);
    return tmp[3] + tmp[2] * 10 + tmp[1] * 100 + tmp[0] * 1000;
}

int main()
{
    int num;
    cin >> num;
    int a1, a2, a3, a4;
    a1 = num % 10;
    a2 = (num - a1) / 10 % 10;
    a3 = (num - 10 * a2 - a1) / 100 % 10;
    a4 = num / 1000;
    if (a1 == a2 && a2 == a3 && a3 == a4)
    {
        printf("%d - %d = 0000", num, num);
        return 0;
    }
    int sub1 = downsort(a1, a2, a3, a4);
    int sub2 = upsort(a1, a2, a3, a4);
    int ans = sub1 - sub2;
    printf("%04d - %04d = %04d\n", sub1, sub2, ans);
    num = ans;
    while (num != 6174)
    {
        a1 = num % 10;
        a2 = (num - a1) / 10 % 10;
        a3 = (num - 10 * a2 - a1) / 100 % 10;
        a4 = num / 1000;
        int sub1 = downsort(a1, a2, a3, a4);
        int sub2 = upsort(a1, a2, a3, a4);
        int ans = sub1 - sub2;
        printf("%04d - %04d = %04d\n", sub1, sub2, ans);
        num = ans;
    }
    return 0;
}