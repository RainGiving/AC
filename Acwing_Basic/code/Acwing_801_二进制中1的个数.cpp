#include <iostream>
using namespace std;

const int N = 100010;
int x, n;

int lowbit(int x)
{
    return x & -x;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int res = 0;
        scanf("%d", &x);
        while(x)
        {
            x -= lowbit(x);
            res++;
        }
        printf("%d ", res);
    }
    return 0;
}