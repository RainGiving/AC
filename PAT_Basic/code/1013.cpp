#include <iostream>
using namespace std;
int primes[1001000], cnt = 0;
bool st[1001000];

void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (st[i])
            continue;
        primes[cnt++] = i;
        for (int j = 2 * i; j <= n; j += i)
            st[j] = true;
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    get_primes(1000005);
    int cnt = 1, i = m - 1;
    while (i < n)
    {
        if (cnt == 1)
            cout << primes[i++];
        else if (cnt % 10 == 1)
        {
            cout << endl;
            cout << primes[i++];
        }
        else
            cout << " " << primes[i++];
        cnt++;
    }

    return 0;
}