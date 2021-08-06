#include <iostream>
using namespace std;
int main()
{
    int c1, c2;
    cin >> c1 >> c2;
    int s = (c2 - c1) / 100;
    if (50 <= (c2 - c1) % 100)
        s++;
    int h = s / 3600;
    s = s % 3600;
    int m = s / 60;
    s = s % 60;
    printf("%02d:%02d:%02d", h, m, s);
    return 0;
}