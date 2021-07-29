#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    double n;
    cin >> n;
    const double eps = 1e-7;
    double l = min(0.0, n), r = max(0.0, n);
    if (0 < n && n < 1)
        r = 1;
    if (n < 0 && -1 < n)
        l = -1;
    while (eps < r - l)
    {
        double mid = (l + r) / 2;
        if (0 <= n)
            if (n < (mid * mid * mid))
                r = mid;
            else
                l = mid;
    }
    printf("%lf", l);
    return 0;
}