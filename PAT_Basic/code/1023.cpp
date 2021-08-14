#include <iostream>
using namespace std;
int num[10];
int main()
{
    for (int i = 0; i < 10; i++)
        cin >> num[i];
    int first = 0;
    for (int i = 1; i < 10; i++)
    {
        if (0 < num[i])
        {
            first = i;
            break;
        }
    }
    cout << first;
    num[first]--;
    for (int i = 0; i < 10; i++)
    {
        while (0 < num[i])
        {
            cout << i;
            num[i]--;
        }
    }
    return 0;
}