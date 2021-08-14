#include <iostream>
using namespace std;
int cnt[10];
string n;
int main()
{
    cin >> n;
    for (int i = 0; i < n.size(); i++)
        cnt[n[i] - '0']++;
    for (int i = 0; i < 10; i++)
        if (cnt[i] != 0)
            cout << i << ":" << cnt[i] << endl;
    return 0;
}
