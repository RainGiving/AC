#include <iostream>
#include <string>

using namespace std;

const int N = 100010;
int m;
int e[N], l[N], r[N], idx;

//初始化
void init()
{
    //0表示左端点，1表示右端点
    r[0] = 1, l[1] = 0; 
    idx = 2;
}

//在节点k的右侧插入x
void insert(int k, int x)
{
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}

//删除第k个点
void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}


int main()
{
    init();
    cin >> m;
    while(m--)
    {
        string op;
        int k, x;
        cin >> op;
        if(op == "L")
        {
            cin >> x;
            insert(0, x);  //最左端插入x 等价于 在左端点的右侧插入x
        }
        else if(op == "R")
        {
            cin >> x;
            insert(l[1], x);   //最右端插入x 等价于 在右端点的左侧节点的右侧插入x
        }
        else if(op == "IL")
        {
            cin >> k >> x;
            insert(l[k + 1], x);   //在k的左侧插入x 等价于 在k的左侧节点的右侧插入x
        }
        else if(op == "IR")
        {
            cin >> k >> x;
            insert(k + 1, x);      //在k的右侧插入x
        }
        else if(op == "D")
        {
            cin >> k;
            remove(k + 1);
        }
    }
    for(int i = r[0]; i != 1; i = r[i])
        cout << e[i] << " ";
    return 0;
}

