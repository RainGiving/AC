#include <iostream>
using namespace std;
const int N = 100010;
int stk[N], tt = -1;
int n;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;  scanf("%d", &x);
        while(x <= stk[tt] && 0 <= tt)	tt--;
        if(0 <= tt)	printf("%d ", stk[tt]);
        else		printf("-1 ");
        stk[++tt] = x;
    }
    
    return 0;
}