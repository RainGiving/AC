#include <iostream>
using namespace std;

int primes[100005], cnt;
bool st[100005];
void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (st[i])
            continue;
        primes[cnt++] = i;                  //i是质数
        for (int j = 2 * i; j <= n; j += i) //则i的倍数都不是质数
            st[j] = true;
    }
}

int main()
{
    int N, ans = 0;
    cin >> N;
    get_primes(N);
    for (int i = 0; i < cnt; i++)
        if (primes[i + 1] - primes[i] == 2)
            ans++;
    cout << ans;
    return 0;
}