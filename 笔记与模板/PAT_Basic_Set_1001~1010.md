[TOC]

## [1001 害死人不偿命的(3n+1)猜想 15分](https://pintia.cn/problem-sets/994805260223102976/problems/994805325918486528) 

```cpp
#include<iostream>
using namespace std;
int n, ans;
int main()
{
    cin >> n;
    while(n != 1)
    {
        if(n % 2) 	 n = (3 * n + 1)/2;
        else		 n = n / 2;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
```

## [1002 写出这个数 20分](https://pintia.cn/problem-sets/994805260223102976/problems/994805324509200384) 

```cpp
#include <iostream>
#include <stack>
#include <string>
using namespace ::std;
void py(int n)
{
    if (n == 0)
        printf("ling");
    if (n == 1)
        printf("yi");
    if (n == 2)
        printf("er");
    if (n == 3)
        printf("san");
    if (n == 4)
        printf("si");
    if (n == 5)
        printf("wu");
    if (n == 6)
        printf("liu");
    if (n == 7)
        printf("qi");
    if (n == 8)
        printf("ba");
    if (n == 9)
        printf("jiu");
}

int main()
{
    string n;
    cin >> n;
    int sum = 0;
    //求这一串数字的和
    for(int i = 0; i < n.size(); ++i)
    	sum += n[i] - '0';


    stack<int> s;
    int tmp;
    //将和的各位数从个位开始依次放到栈中
    while (sum != 0)
    {
        tmp = sum % 10;
        sum = sum / 10;
        s.push(tmp);
    }
    //从栈中取出并输出对应的拼音
    while (!s.empty())
    {
        py(s.top());
        s.pop();
        if (!s.empty())
            cout << " ";
    }
    return 0;
}
```

## [1003 我要通过！20分](https://pintia.cn/problem-sets/994805260223102976/problems/994805323154440192) 

首先排除含有其他字母的，多个P和T的，T在P前面的，P和T之间没有A的这几种情况，顺便记录下P之前、P和T之间、T之后的A的数量，对应变量a, b, c

由题目知道，a,b,c满足题意的前提是，a, b - 1, c - a满足题意，数据量小，没有总结数学规律，直接递归求解，递归基是b=1时，a和c如果相等就输出正确，否则就是错误

坑：今天第一次做处理多次数据的问题，输出一个NO之后程序就结束了，bug在使用了控制while(n--)的break，改为continue即可！

```cpp
#include <iostream>
#include <string>
using namespace std;

bool test(int a, int b, int c)
{
    //递归基
    if (b == 1 && a == c)	return true;
    else if (b == 1)		return false;
    
    if (test(a, b - 1, c - a))	return true;
    else	return false;
}

int main()
{
    int n;	cin >> n;
    while (n--)
    {
        string s;	cin >> s;
        bool flag = true;
        int P_index = -1, T_index = -1;
        //先找P和T的位置
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'P')		P_index = i;
            else if (s[i] == 'T')	T_index = i;
        }
        //没有P或T，或者P在T后面，错误
        if (P_index < 0 || T_index < 0 || T_index < P_index)
            flag = false;
        //统计P前面，P和T之间，T之后的A数量
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (i == P_index || i == T_index)	continue;
            else if (s[i] != 'A')
            {
                flag = false;	break;
            }
            else if (i < P_index)					cnt1++;
            else if (P_index < i && i < T_index)	cnt2++;
            else if (T_index < i)					cnt3++;
        }
        if (!flag || cnt2 < 1)
        {
            cout << "NO" << endl;	continue;
        }
        if (test(cnt1, cnt2, cnt3))	cout << "YES" << endl;
        else						cout << "NO" << endl;
    }
    return 0;
}
```

## [1004 成绩排名 20分](https://pintia.cn/problem-sets/994805260223102976/problems/994805321640296448)

```cpp
#include <iostream>
#include <string>
using namespace std;
struct Student
{
    string name;
    string stuid;
    int score;
};

int main()
{
    int n;
    cin >> n;
    int maxScore = -1, minScore = 101;
    string bestName, bestStuid, worstName, worstStuid;
    struct Student st;
    for (int i = 0; i < n; i++)
    {
        cin >> st.name >> st.stuid >> st.score;
        if (maxScore < st.score)
        {
            maxScore = st.score;
            bestName = st.name;
            bestStuid = st.stuid;
        }
        if (st.score < minScore)
        {
            minScore = st.score;
            worstName = st.name;
            worstStuid = st.stuid;
        }
    }
    cout << bestName << " " << bestStuid << endl;
    cout << worstName << " " << worstStuid << endl;
    return 0;
}
```

## [1005 继续(3n+1)猜想 25分](https://pintia.cn/problem-sets/994805260223102976/problems/994805320306507776)

下面是第一次做这道题采用的朴实无华的暴力方法，数据量小就直接过了，有更巧妙的方法再补充吧

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    int data;
    bool is = true; //是否是关键值
} a[105];
int n;
int find(int x)
{
    for (int i = 0; i < n; i++)
        if (a[i].data == x)	return i;
    return -1;
}
bool cmp(struct node a, struct node b)
{
    return b.data < a.data; //使用sort从大到小排列
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].data;
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
    {
        int cnt = 5000, tmp = a[i].data;
        while (cnt--)
        {
            if (tmp % 2 == 0)	tmp /= 2;
            else	tmp = (3 * tmp + 1) / 2;
            if (find(tmp) == -1)	continue;
            else	a[find(tmp)].is = false;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (a[i].is)	cnt++;
    for (int i = 0; i < n; i++)
        if (a[i].is && 1 < cnt)
        {
            cout << a[i].data << ' ';	cnt--;
        }
        else if (a[i].is && cnt == 1)
            cout << a[i].data;
    return 0;
}
```

## [1006 换个格式输出整数 15分](https://pintia.cn/problem-sets/994805260223102976/problems/994805318855278592)

```cpp
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int cntb = n / 100, cnts = (n % 100) / 10, cntg = n % 10;
    for (int i = 0; i < cntb; i++)
        cout << 'B';
    for (int i = 0; i < cnts; i++)
        cout << 'S';
    for (int i = 1; i <= cntg; i++)
        cout << i;
    return 0;
}
```

## [1007 素数对猜想 20分](https://pintia.cn/problem-sets/994805260223102976/problems/994805317546655744)

素数或质数 是从2开始的整数且只有1和本身这两个约数，先用素数筛把题目数据范围里的素数求出来放到数组中，再对素数数组进行遍历，判断是否满足素数对进行计数即可

这里使用的是朴素筛法求素数，我们建立一个标记数组，每求出一个素数，那么这个素数的所有倍数都不可能是素数，就将它的所有倍数在标记数组中置为否，就不用再判断这些数是否是素数了

素数模板在此https://www.acwing.com/blog/content/406/

```cpp
#include <iostream>
using namespace std;

int primes[100005], cnt;
bool st[100005];
void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (st[i])
            continue;
        primes[cnt++] = i;                  //i是质数
        for (int j = 2 * i; j <= n; j += i) //则i的倍数都不是质数
            st[j] = true;
    }
}

int main()
{
    int N, ans = 0;
    cin >> N;
    get_primes(N);
    for (int i = 0; i < cnt; i++)
        if (primes[i + 1] - primes[i] == 2)
            ans++;
    cout << ans;
    return 0;
}
```

## [1008 数组元素循环右移问题 20分※](https://pintia.cn/problem-sets/994805260223102976/problems/994805316250615808)

*哎呀，好累，这题还有两个点没过，明天加油了,题目不让使用新数组，但是这样简单好多，有时间补正经的链表实现吧*

这题坑点在**M有可能大于N**，M = N时相当于整个数组没有发生变化，因此必须要有 M = M % N 这一步，这样这两个点就过了

```cpp
#include <iostream>
using namespace std;
int a[300], b[300];
int main()
{
    int n, m;
    cin >> n >> m;
    m = m % n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int j = 0;
    for (int i = n - m; i < n; i++)
        b[j++] = a[i];
    for (int i = 0; i < n - m; i++)
        b[j++] = a[i];
    for (int i = 0; i < n - 1; i++)
        cout << b[i] << ' ';
    cout << b[n - 1];
    return 0;
}
```

## [1009 说反话 20分](https://pintia.cn/problem-sets/994805260223102976/problems/994805314941992960)

```cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack<string> ss;
    string str;
    while (cin >> str)
        ss.push(str);

    while (!ss.empty() && 1 < ss.size())
    {
        cout << ss.top() << " ";
        ss.pop();
    }
    cout << ss.top();
    ss.pop();
    return 0;
}
```

## [1010 一元多项式求导 25分※](https://pintia.cn/problem-sets/994805260223102976/problems/994805313708867584)

简单地把系数乘以指数，再将指数减1，如果指数小于0就不输出（相当于原式的指数为0，求导后此项为0了），错误两个点，代码如下<img src="https://raw.githubusercontent.com/RainGiving/PictureBed/master/img1/20210729203434.png" alt="image-20210729203434270" style="zoom:80%;" />

```cpp
#include <iostream>
using namespace std;

int main()
{
    int e, c;
    cin >> c >> e;
    c = e * c;
    e = e - 1;
    if (0 <= e)
        cout << c << " " << e;

    while (cin >> c >> e)
    {
        c = e * c;
        e = e - 1;
        if (0 <= e)
            cout << " " << c << " " << e;
    }
    return 0;
}
```

后来，理解一下这句话的意思

以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。注意“**零多项式**”的指数和系数都是 0，但是表示为 `0 0`。

前面我们说指数小于零就不输出的前提是这个多项式不是零多项书，对于零多项式，必须要输出0 0，因此第一次输出和后面的输出应该进行区别，第一次输入如果是零多项式就输出0 0 结束程序即可，这两个点应该就错在这

![image-20210729204433492](https://raw.githubusercontent.com/RainGiving/PictureBed/master/img1/20210729204433.png)

```cpp
#include <iostream>
using namespace std;

int main()
{
    int e, c;
    cin >> c >> e;
    if (e == 0)
        cout << 0 << " " << 0;
    else
    {
        c = e * c;
        e = e - 1;
        cout << c << " " << e;
    }

    while (cin >> c >> e)
    {
        if (e != 0)
        {
            c = e * c;
            e = e - 1;
            cout << " " << c << " " << e;
        }
    }
    return 0;
}
```

## [1011 A+B和C 15分](https://pintia.cn/problem-sets/994805260223102976/problems/994805312417021952)

给定区间 [−2^31,2^31] 内的 3 个整数 *A*、*B* 和 *C*，请判断 *A*+*B* 是否大于 *C*。

**输入格式**：

输入第 1 行给出正整数 *T* (≤10)，是测试用例的个数。随后给出 *T* 组测试用例，每组占一行，顺序给出 *A*、*B* 和 *C*。整数间以空格分隔。

**输出格式**：

对每组测试用例，在一行中输出 `Case #X: true` 如果 *A*+*B*>*C*，否则输出 `Case #X: false`，其中 `X` 是测试用例的编号（从 1 开始）。

**输入样例**：

```in
4
1 2 3
2 3 4
2147483647 0 2147483646
0 -2147483648 -2147483647
```

**输出样例**：

```out
Case #1: false
Case #2: true
Case #3: true
Case #4: false
```

```cpp
#include <iostream>
using namespace std;
#define ll long long

int main()
{
    ll a, b, c, T;
    cin >> T;
    int i = 0;
    while (T--)
    {
        cin >> a >> b >> c;
        cout << "Case #" << ++i << ": ";
        if (a - c > -b)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
```

## [1012 数字分类 20分](https://pintia.cn/problem-sets/994805260223102976/problems/994805311146147840)

给定一系列正整数，请按要求对数字进行分类，并输出以下 5 个数字：

- *A*1 = 能被 5 整除的数字中所有偶数的和；
- *A*2 = 将被 5 除后余 1 的数字按给出顺序进行交错求和，即计算 *n*1−*n*2+*n*3−*n*4⋯；
- *A*3 = 被 5 除后余 2 的数字的个数；
- *A*4 = 被 5 除后余 3 的数字的平均数，精确到小数点后 1 位；
- *A*5 = 被 5 除后余 4 的数字中最大数字。

输入格式：

每个输入包含 1 个测试用例。每个测试用例先给出一个不超过 1000 的正整数 *N*，随后给出 *N* 个不超过 1000 的待分类的正整数。数字间以空格分隔。

输出格式：

对给定的 *N* 个正整数，按题目要求计算 *A*1~*A*5 并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若其中某一类数字不存在，则在相应位置输出 `N`。

输入样例 1：

```in
13 1 2 3 4 5 6 7 8 9 10 20 16 18
```

输出样例 1：

```out
30 11 2 9.7 9
```

输入样例 2：

```in
8 1 2 4 5 6 7 9 16
```

输出样例 2：

```out
N 11 2 N 9
```

```cpp
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

```

## [1013 数素数 20分](https://pintia.cn/problem-sets/994805260223102976/problems/994805309963354112)

![image-20210729220930247](https://raw.githubusercontent.com/RainGiving/PictureBed/master/img1/20210729220930.png)

使用素数筛，尽量把范围开大一点，一开始有一个点没过，把素数开到五位数直接过了

```cpp
#include <iostream>
using namespace std;
int primes[1001000], cnt = 0;
bool st[1001000];

void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (st[i])
            continue;
        primes[cnt++] = i;
        for (int j = 2 * i; j <= n; j += i)
            st[j] = true;
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    get_primes(1000005);
    int cnt = 1, i = m - 1;
    while (i < n)
    {
        if (cnt == 1)
            cout << primes[i++];
        else if (cnt % 10 == 1)
        {
            cout << endl;
            cout << primes[i++];
        }
        else
            cout << " " << primes[i++];
        cnt++;
    }

    return 0;
}
```

## [1014 福尔摩斯的约会 20分](https://pintia.cn/problem-sets/994805260223102976/problems/994805308755394560)

大侦探福尔摩斯接到一张奇怪的字条：`我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm`。大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间`星期四 14:04`，因为前面两字符串中第 1 对相同的大写英文字母（大小写有区分）是第 4 个字母 `D`，代表星期四；第 2 对相同的字符是 `E` ，那是第 5 个英文字母，代表一天里的第 14 个钟头（于是一天的 0 点到 23 点由数字 0 到 9、以及大写字母 `A` 到 `N` 表示）；后面两字符串第 1 对相同的英文字母 `s` 出现在第 4 个位置（从 0 开始计数）上，代表第 4 分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

输入格式：

输入在 4 行中分别给出 4 个非空、不包含空格、且长度不超过 60 的字符串。

输出格式：

在一行中输出约会的时间，格式为 `DAY HH:MM`，其中 `DAY` 是某星期的 3 字符缩写，即 `MON` 表示星期一，`TUE` 表示星期二，`WED` 表示星期三，`THU` 表示星期四，`FRI` 表示星期五，`SAT` 表示星期六，`SUN` 表示星期日。题目输入保证每个测试存在唯一解。

输入样例：

```in
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
```

输出样例：

```out
THU 14:04
```

注意1：根据大写字母确认星期几，大写字母不是A~Z，而是A~G（只有前七个大写字母有意义）

注意2：根据数字或大写字母确认几时，大写字母范围是A~N，数字范围0~9

```cpp
#include <iostream>
#include <string>
using namespace std;
string s1, s2, s3, s4;

int main()
{
    cin >> s1 >> s2 >> s3 >> s4;
    char week, clock, minute;
    bool flag = false;
    for (int i = 0; i < min(s1.size(), s2.size()); i++)
    {
        if (s1[i] == s2[i] && flag == false && 0 <= s1[i] - 'A' && s1[i] - 'G' <= 0) // A ~ G
        {
            week = s1[i];
            flag = true;
            i++;
        }
        if (s1[i] == s2[i] && flag && (0 <= s1[i] - 'A' && s1[i] - 'N' <= 0 || 0 <= s1[i] - '0' && s1[i] - '0' <= 9)) // 0 ~ 9  A ~ N
        {
            clock = s1[i];
            break;
        }
    }
    for (int i = 0; i < min(s3.size(), s4.size()); i++)
    {
        if (s3[i] == s4[i] && (0 <= s3[i] - 'A' && s3[i] - 'Z' <= 0 || 0 <= s3[i] - 'a' && s3[i] - 'z' <= 0))
        {
            minute = i;
            break;
        }
    }
    if (week == 'A')
        cout << "MON";
    else if (week == 'B')
        cout << "TUE";
    else if (week == 'C')
        cout << "WED";
    else if (week == 'D')
        cout << "THU";
    else if (week == 'E')
        cout << "FRI";
    else if (week == 'F')
        cout << "SAT";
    else if (week == 'G')
        cout << "SUN";

    if (0 <= clock - '0' && clock - '0' <= 9)
        printf(" %02d", clock - '0');
    else
        printf(" %d", clock - 'A' + 10);
    printf(":%02d", minute);
    return 0;
}
```



