#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    char flag1, front_dot, flag2; //实数正负，实数小数点前一位，指数正负
    int e;                        //指数绝对值
    char after_dot[100005];       //实数小数部分
    string str;
    scanf("%c%c.%[^E]E%c%d", &flag1, &front_dot, &after_dot, &flag2, &e);
    if (flag2 == '+') //指数大于0
    {
        str = str + front_dot;
        str = str + after_dot;
        int len = str.size();
        if (len - 1 < e) //需要在后面补e-len+1个0
        {
            for (int i = 0; i < e - len + 1; i++)
                str = str + '0';
        }
        else if (e < len - 1) //改变小数点的位置即可
            str.insert(e + 1, ".");
        // e = len - 1时无需处理
    }
    else //指数小于0
    {
        for (int i = 0; i < e; i++)
        {
            if (i == 1)
                str = str + '.';
            str = str + '0';
        }
        str = str + front_dot;
        str = str + after_dot;
    }

    if (flag1 == '-')
        str.insert(0, "-");
    cout << str;
    return 0;
}