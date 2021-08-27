#include <iostream>
using namespace std;

const int N = 100010;

//head表示头节点下标
//e[i]表示节点i的值
//ne[i]表示节点i的下一个节点的下标(next指针)
//idx表示当前使用到到哪个点(即后面我们要插入等操作增加链表中的节点，新增节点的下标就应是idx)
int head, e[N], ne[N], idx;
int m;

//初始化
void init()
{
    head = -1;  //初始头节点为空节点
    idx = 0;    //当前使用的节点从0开始
}

//将value为x的节点插入，使之成为头节点，最常用
void add_to_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}

//将value为x的节点插入到下标为k的节点的后面
void add(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

//将下标是k的节点的后面的节点删除
void remove(int k)
{
    if(k == -1)  head = ne[head];    //题目特殊条件，删除头节点
    ne[k] = ne[ne[k]];
}


int main()
{
    init(); //初始化
    cin >> m;
    while(m--)
    {
        char op;
        int k, x;
        //这里在%c前加上一个" "防止读入的是上一次输入的回车
        //这种情况还是建议使用cin
        scanf(" %c", &op);
        if(op == 'H')
        {
            scanf("%d", &x);
            add_to_head(x);
        }
        else if(op == 'D')
        {
            scanf("%d", &k);
            remove(k - 1);
        }
        else
        {
            scanf("%d%d", &k, &x);
            add(k - 1, x);
        }
    }
    
    for(int i = head; i != -1; i = ne[i])    printf("%d ", e[i]);
    return 0;
}