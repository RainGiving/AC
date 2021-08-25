#include <iostream>
using namespace std;

const double eps = 1e-8;
double n;

double bsearch(double l, double r)
{
    while(eps < r - l)
    {
        double mid = (l + r) / 2;
        if(mid * mid * mid < n) l = mid;
        else                    r = mid;
    }
    return l;
}

int main()
{
    cin >> n;
    printf("%.6f", bsearch(-10000, 10000));
    return 0;
}