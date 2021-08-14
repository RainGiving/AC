#include <iostream>
#include <algorithm>
using namespace std;
int data[100005], nex[100005];

int main()
{
    int first, n, k;
    cin >> first >> n >> k;
    int head = 100003, before_front = head;
    nex[head] = first; //设定一个头节点
    //读入各节点
    while (n--)
    {
        int tmp;
        cin >> tmp;
        cin >> data[tmp] >> nex[tmp];
    }
    //统计在第一个节点链表上的节点数
    int i = first, node_cnt = 0;
    while (i != -1)
    {
        node_cnt++;
        i = nex[i];
    }

    int front = first, loop_cnt = node_cnt / k;

    //New是nex[New]已经逆转完毕的头节点地址，初始化为第一个节点地址
    //Old是待逆转其nex[Old]为New的节点地址
    //Tmp是记录未逆转时的new[Old]
    while (loop_cnt--)
    {
        int New = front, Old, Tmp = nex[front];
        int cnt = k - 1;
        while (cnt--)
        {
            Old = Tmp;
            Tmp = nex[Old];
            nex[Old] = New;
            New = Old;
        }
        //头节点特殊处理
        nex[before_front] = New;
        nex[front] = Tmp;

        //为后面k个要反转的节点做准备
        before_front = front;
        front = Tmp;
    }

    //输出
    int j = nex[head];
    while (true)
    {
        if (nex[j] != -1)
        {
            printf("%05d %d %05d\n", j, data[j], nex[j]);
            j = nex[j];
        }
        else
        {
            printf("%05d %d %d\n", j, data[j], nex[j]);
            break;
        }
    }
    return 0;
}
