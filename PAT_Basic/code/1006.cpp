#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int cntb = n / 100, cnts = (n % 100) / 10, cntg = n % 10;
    for (int i = 0; i < cntb; i++)
        cout << 'B';
    for (int i = 0; i < cnts; i++)
        cout << 'S';
    for (int i = 1; i <= cntg; i++)
        cout << i;
    return 0;
}