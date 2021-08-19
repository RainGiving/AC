#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> add(vector<int> &A, vector<int> &B)
{
    int t = 0;
    vector<int> C;
    for(int i = 0; i < A.size() || i < B.size(); i++)
    {
        if(i < A.size())    t += A[i];
        if(i < B.size())    t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if(t != 0)  C.push_back(t % 10);
    return C;
}


int main()
{
    string a, b;
    cin >> a >> b;
    vector<int> A, B, C;
    for(int i = a.size() - 1; 0 <= i; i--)  A.push_back(a[i] - '0');
    for(int i = b.size() - 1; 0 <= i; i--)  B.push_back(b[i] - '0');
    C = add(A, B);
    for(int i = C.size() - 1; 0 <= i; i--)  printf("%d", C[i]);
    return 0;
}