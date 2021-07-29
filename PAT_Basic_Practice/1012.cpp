#include <iostream>
using namespace std;
int num[10010];
int N;
int a1, a2, a3, a5;
float a4;
bool s1 = false, s2 = false, s3 = false, s4 = false, s5 = false;
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> num[i];
    bool flag2 = true;
    int cnt4 = 0;
    float sum4 = 0;
    for (int i = 0; i < N; i++)
    {
        if (num[i] % 5 == 0 && num[i] % 2 == 0)
        {
            a1 += num[i];
            s1 = true;
        }

        if (num[i] % 5 == 1 && flag2)
        {
            a2 += num[i];
            flag2 = !flag2;
            s2 = true;
        }
        else if (num[i] % 5 == 1)
        {
            a2 -= num[i];
            flag2 = !flag2;
        }

        if (num[i] % 5 == 2)
        {
            a3++;
            s3 = true;
        }

        if (num[i] % 5 == 3)
        {
            sum4 += num[i];
            cnt4++;
            s4 = true;
        }
        if (num[i] % 5 == 4 && a5 < num[i])
        {
            a5 = num[i];
            s5 = true;
        }
    }
    if (s1)
        cout << a1 << " ";
    else
        cout << "N"
             << " ";
    if (s2)
        cout << a2 << " ";
    else
        cout << "N"
             << " ";
    if (s3)
        cout << a3 << " ";
    else
        cout << "N"
             << " ";
    if (s4)
    {
        a4 = sum4 * 1.0 / (cnt4 * 1.0);
        printf("%.1f ", a4);
    }
    else
        cout << "N"
             << " ";
    if (s5)
        cout << a5;
    else
        cout << "N";

    return 0;
}
