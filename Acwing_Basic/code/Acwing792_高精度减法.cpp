#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool cmp(vector<int> &A, vector<int> &B)
{
    if(A.size() != B.size())    return B.size() < A.size();
    for(int i = A.size() - 1; 0 <= i; i--)
        if(A[i] != B[i])    return B[i] < A[i];
    return true;
}

vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    int t = 0;
    for(int i = 0; i < A.size(); i++)
    {
        t = A[i] - t;
        if(i < B.size())    t -= B[i];
        if(0 <= t)
        {
            C.push_back(t);         t = 0;
        }
        else
        {
            C.push_back(t + 10);    t = 1;
        }
    }
    while(1 < C.size() && C.back() == 0)  C.pop_back();
    return C;
}


int main()
{
    string a, b;
    cin >> a >> b;
    vector<int> A, B, C;
    for(int i = a.size() - 1; 0 <= i; i--)  A.push_back(a[i] - '0');
    for(int i = b.size() - 1; 0 <= i; i--)  B.push_back(b[i] - '0');
    if(cmp(A, B))
    {
        C = sub(A, B);
        for(int i = C.size() - 1; 0 <= i; i--)  printf("%d", C[i]);
    }
    else
    {
        C = sub(B, A);
        printf("-");
        for(int i = C.size() - 1; 0 <= i; i--)  printf("%d", C[i]);
    }
    return 0;
}