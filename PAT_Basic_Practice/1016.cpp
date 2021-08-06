#include <iostream>
#include <string>
using namespace std;
string A, B;
char a, b;
int main()
{
    int cnt1 = 0, cnt2 = 0;
    cin >> A >> a >> B >> b;
    for (int i = 0; i < A.size(); i++)
        if (A[i] == a)
            cnt1++;
    for (int i = 0; i < B.size(); i++)
        if (B[i] == b)
            cnt2++;
    int numa = a - '0', numb = b - '0', pa = 0, pb = 0;
    int tmp = 1;
    if (cnt1 == 0)
        pa = 0;
    else
        for (int i = 0; i < cnt1; i++)
        {
            pa += numa * tmp;
            tmp *= 10;
        }
    tmp = 1;
    if (cnt2 == 0)
        pb = 0;
    else
        for (int i = 0; i < cnt2; i++)
        {
            pb += numb * tmp;
            tmp *= 10;
        }
    cout << pa + pb;
    return 0;
}