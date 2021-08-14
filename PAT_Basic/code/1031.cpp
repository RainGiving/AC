#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    while (n--)
    {
        int sum = 0, qz[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
        char id[17], rear;
        bool flag = true;
        for (int i = 0; i < 17; i++)
        {
            cin >> id[i];
            if ('0' <= id[i] && id[i] <= '9')
            {
                sum += (id[i] - '0') * qz[i];
            }
            else
                flag = false;
        }
        cin >> rear;
        if (flag)
        {
            int z = sum % 11;
            char check[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
            if (rear != check[z])
                flag = false;
        }
        if (!flag)
        {
            cnt++;
            for (int i = 0; i < 17; i++)
                cout << id[i];
            cout << rear << endl;
        }
    }
    if (cnt == 0)
        cout << "All passed" << endl;
}