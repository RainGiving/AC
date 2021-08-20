#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> mul(vector<int> &A, int b)
{
    vector<int> C;
    if(b == 0)
    {
        C.push_back(0);
        return C;
    }
    int t = 0;
    for(int i = 0; i < A.size(); i++)
    {
        t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    if(t != 0)  C.push_back(t);
    return C;
}


int main()
{
    string a;
    int b;
    cin >> a >> b;
    vector<int> A, C;
    for(int i = a.size() - 1; 0 <= i; i--)  A.push_back(a[i] - '0');
    C = mul(A, b);
    for(int i = C.size() - 1; 0 <= i; i--)  printf("%d", C[i]);
    return 0;
}