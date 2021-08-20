#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> div(vector<int> &A, int b, int &r)
{
    vector<int> C;
    for(int i = A.size() - 1; 0 <= i; i--)
    {
        r = A[i] + r * 10;
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());    //除法计算得到的C是从高位到低位，为了和其他运算保持一致，这里将其逆转为低位到高位，统一逆序输出
    while(1 < C.size() && C.back() == 0)    //删除前导0
        C.pop_back();
    return C;
}

int main()
{
    string a;
    int b, r = 0;
    cin >> a >> b;
    vector<int> A, C;
    for(int i = a.size() - 1; 0 <= i; i--)  A.push_back(a[i] - '0');
    C = div(A, b, r);
    for(int i = C.size() - 1; 0 <= i; i--)  printf("%d", C[i]);
    cout << endl;
    cout << r;
    return  0;
}