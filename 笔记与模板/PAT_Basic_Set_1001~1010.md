[TOC]

## [1001 害死人不偿命的(3n+1)猜想 15分](https://pintia.cn/problem-sets/994805260223102976/problems/994805325918486528)  秒

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

## [1002 写出这个数 20分](https://pintia.cn/problem-sets/994805260223102976/problems/994805324509200384) 秒

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

### 坑点：理解题意有误，`xPATx`没有注意到应该左右两个字符串`x`相同

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

## [1004 成绩排名 20分](https://pintia.cn/problem-sets/994805260223102976/problems/994805321640296448) 秒

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

## [1005 继续(3n+1)猜想 25分](https://pintia.cn/problem-sets/994805260223102976/problems/994805320306507776) 秒

下面是第一次做这道题采用的朴实无华的暴力方法，数据量小 就直接过了，有更巧妙的方法再补充吧

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

## [1006 换个格式输出整数 15分 ](https://pintia.cn/problem-sets/994805260223102976/problems/994805318855278592) 秒

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

## [1007 素数对猜想 20分](https://pintia.cn/problem-sets/994805260223102976/problems/994805317546655744) 秒

### 知识点：素数筛模板

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

## [1008 数组元素循环右移问题 20分](https://pintia.cn/problem-sets/994805260223102976/problems/994805316250615808)

### 坑点：没有注意题目细节，M有可能大于N

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

## [1009 说反话 20分](https://pintia.cn/problem-sets/994805260223102976/problems/994805314941992960) 秒

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

## [1010 一元多项式求导 25分](https://pintia.cn/problem-sets/994805260223102976/problems/994805313708867584)

### 坑点：没有注意题目细节，零多项式需要特殊处理

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

## [1011 A+B和C 15分](https://pintia.cn/problem-sets/994805260223102976/problems/994805312417021952) 秒

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

## [1012 数字分类 20分](https://pintia.cn/problem-sets/994805260223102976/problems/994805311146147840) 秒

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

### 知识点：素数筛模板，可以把素数数组开得大些

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

## [1014 福尔摩斯的约会 20分 ](https://pintia.cn/problem-sets/994805260223102976/problems/994805308755394560)

### 坑点：没有注意题目细节，各对相同的字符都有一定限制，全部加上判断语句实现好才能AC

大侦探福尔摩斯接到一张奇怪的字条：`我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm`。大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间`星期四 14:04`，因为前面两字符串中第 1 对相同的**大写英文字母**（大小写有区分）是第 4 个字母 `D`，代表星期四；第 2 对**相同的字符**是 `E` ，那是第 5 个英文字母，代表一天里的第 14 个钟头（于是一天的 0 点到 23 点由数字 0 到 9、以及大写字母 `A` 到 `N` 表示）；后面两字符串第 1 对**相同的英文字母** `s` 出现在第 4 个位置（从 0 开始计数）上，代表第 4 分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

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

## [1015 德才论 25分](https://pintia.cn/problem-sets/994805260223102976/problems/994805307551629312) 秒

宋代史学家司马光在《资治通鉴》中有一段著名的“德才论”：“是故才德全尽谓之圣人，才德兼亡谓之愚人，德胜才谓之君子，才胜德谓之小人。凡取人之术，苟不得圣人，君子而与之，与其得小人，不若得愚人。”

现给出一批考生的德才分数，请根据司马光的理论给出录取排名。

输入格式：

输入第一行给出 3 个正整数，分别为：*N*（≤10^5），即考生总数；*L*（≥60），为录取最低分数线，即德分和才分均不低于 *L* 的考生才有资格被考虑录取；*H*（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；德才分均低于 *H*，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；其他达到最低线 *L* 的考生也按总分排序，但排在第三类考生之后。

随后 *N* 行，每行给出一位考生的信息，包括：`准考证号 德分 才分`，其中`准考证号`为 8 位整数，德才分为区间 [0, 100] 内的整数。数字间以空格分隔。

输出格式：

输出第一行首先给出达到最低分数线的考生人数 *M*，随后 *M* 行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。

输入样例：

```in
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
```

输出样例：

```out
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90
```

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
struct Student
{
    int id;    //准考证号
    int de;    //德育分
    int cai;   //才育分
    int total; //总分
} stu[100005], rank1[100005], rank2[100005], rank3[100005], rank4[100005];
int cnt1, cnt2, cnt3, cnt4;
bool cmp(struct Student a, struct Student b)
{
    if (a.total != b.total)
        return b.total < a.total;
    else if (a.de != b.de)
        return b.de < a.de;
    else
        return a.id < b.id;
}
int main()
{
    int n, l, h; //考生总数，录取最低分数线，优先录取线
    cin >> n >> l >> h;
    for (int i = 0; i < n; ++i)
    {
        cin >> stu[i].id >> stu[i].de >> stu[i].cai;
        stu[i].total = stu[i].de + stu[i].cai;
        if (h <= stu[i].de && h <= stu[i].cai) //德才全尽第一类
            rank1[cnt1++] = stu[i];
        else if (h <= stu[i].de && stu[i].cai < h && l <= stu[i].cai) //德胜才 第二类
            rank2[cnt2++] = stu[i];
        else if (stu[i].de < h && stu[i].cai < h && stu[i].cai <= stu[i].de && l <= stu[i].de && l <= stu[i].cai) //德才全亡但是德胜才 第三类
            rank3[cnt3++] = stu[i];
        else if (l <= stu[i].de && l <= stu[i].cai) //其他达到最低线的
            rank4[cnt4++] = stu[i];
    }

    sort(rank1, rank1 + cnt1, cmp);
    sort(rank2, rank2 + cnt2, cmp);
    sort(rank3, rank3 + cnt3, cmp);
    sort(rank4, rank4 + cnt4, cmp);

    cout << cnt1 + cnt2 + cnt3 + cnt4 << endl;
    for (int i = 0; i < cnt1; i++)
        cout << rank1[i].id << " " << rank1[i].de << " " << rank1[i].cai << endl;
    for (int i = 0; i < cnt2; i++)
        cout << rank2[i].id << " " << rank2[i].de << " " << rank2[i].cai << endl;
    for (int i = 0; i < cnt3; i++)
        cout << rank3[i].id << " " << rank3[i].de << " " << rank3[i].cai << endl;
    for (int i = 0; i < cnt4; i++)
        cout << rank4[i].id << " " << rank4[i].de << " " << rank4[i].cai << endl;
    return 0;
}
```

## [1016 部分A+B 15分](https://pintia.cn/problem-sets/994805260223102976/problems/994805306310115328) 秒

![image-20210730145523816](https://raw.githubusercontent.com/RainGiving/PictureBed/master/img1/20210730145523.png)

```cpp
#include <iostream>
#include <string>
using namespace std;
string A, B;
char a, b;
int main()
{
    int cnt1 = 0, cnt2 = 0;
    cin >> A >> a >> B >> b;
    for (int i = 0; i < A.size(); i++)
        if (A[i] == a)
            cnt1++;
    for (int i = 0; i < B.size(); i++)
        if (B[i] == b)
            cnt2++;
    int numa = a - '0', numb = b - '0', pa = 0, pb = 0;
    int tmp = 1;
    if (cnt1 == 0)
        pa = 0;
    else
        for (int i = 0; i < cnt1; i++)
        {
            pa += numa * tmp;
            tmp *= 10;
        }
    tmp = 1;
    if (cnt2 == 0)
        pb = 0;
    else
        for (int i = 0; i < cnt2; i++)
        {
            pb += numb * tmp;
            tmp *= 10;
        }
    cout << pa + pb;
    return 0;
}
```

## [1017 A除以B 20分](https://pintia.cn/problem-sets/994805260223102976/problems/994805305181847552)

### 坑点：没有注意题目细节，没有考虑B大于A的情况

![image-20210730151204071](https://raw.githubusercontent.com/RainGiving/PictureBed/master/img1/20210730151204.png)

一开始忽略了A可能小于B的情况导致有一个点没过，加了新的判断后已解决

```cpp
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a;
    int b;
    cin >> a >> b;
    int cur = a[0] - '0', bef = 0;
    if (cur < b && a.size() == 1)
    {
        cout << 0;
        bef = cur * 10;
    }
    else if (cur < b)
        bef = cur * 10;
    else
    {
        cout << cur / b;
        bef = (cur - (cur / b) * b) * 10;
    }
    for (int i = 1; i < a.size(); i++)
    {
        cur = a[i] - '0' + bef;
        if (cur < b)
        {
            cout << 0;
            bef = cur * 10;
        }
        else
        {
            cout << cur / b;
            bef = (cur - (cur / b) * b) * 10;
        }
    }
    cout << " " << bef / 10;
    return 0;
}
```

## [1018 锤子剪刀布 20分](https://pintia.cn/problem-sets/994805260223102976/problems/994805304020025344)

### 题目简单，一个`==`写成了`=`导致迷糊半天

大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：

![FigCJB.jpg](https://images.ptausercontent.com/724da598-b37f-4f1f-99b4-71459654ce3a.jpg)

现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：

输入第 1 行给出正整数 *N*（≤105），即双方交锋的次数。随后 *N* 行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。`C` 代表“锤子”、`J` 代表“剪刀”、`B` 代表“布”，第 1 个字母代表甲方，第 2 个代表乙方，中间有 1 个空格。

输出格式：

输出第 1、2 行分别给出甲、乙的胜、平、负次数，数字间以 1 个空格分隔。第 3 行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有 1 个空格。如果解不唯一，则输出按字母序最小的解。

输入样例：

```in
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
```

输出样例：

```out
5 3 2
2 3 5
B B
```

```cpp
#include <iostream>
using namespace std;
int n;

char themax(int c, int j, int b)
{
    if (c == j && j == b || b == c && j < b || b == j && c < b)
        return 'B';
    else if (c == j && b < c)
        return 'C';
    else if (c < j && b < j)
        return 'J';
    else if (c < b && j < b)
        return 'B';
    else if (j < c && b < c)
        return 'C';
}

//判断输赢，a赢返回1，b赢返回-1，平局返回0
int win(char a, char b)
{
    if (a == 'C')
    {
        if (b == 'J')
            return 1;
        else if (b == 'B')
            return -1;
        else
            return 0;
    }
    else if (a == 'J')
    {
        if (b == 'B')
            return 1;
        else if (b == 'C')
            return -1;
        else
            return 0;
    }
    else if (a == 'B')
    {
        if (b == 'C')
            return 1;
        else if (b == 'J')	//一开始这个==写成了=，成功导致蜜汁错误
            return -1;
        else
            return 0;
    }
}

int main()
{
    cin >> n;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    int win1c = 0, win1j = 0, win1b = 0, win2c = 0, win2j = 0, win2b = 0;
    while (n--)
    {
        char a, b;
        cin >> a >> b;
        if (0 < win(a, b))
        {
            cnt1++;
            if (a == 'C')
                win1c++;
            else if (a == 'J')
                win1j++;
            else if (a == 'B')
                win1b++;
        }
        else if (win(a, b) < 0)
        {
            cnt2++;
            if (b == 'C')
                win2c++;
            else if (b == 'J')
                win2j++;
            else if (b == 'B')
                win2b++;
        }
        else
            cnt3++;
    }

    cout << cnt1 << " " << cnt3 << " " << cnt2 << endl;
    cout << cnt2 << " " << cnt3 << " " << cnt1 << endl;
    cout << themax(win1c, win1j, win1b) << " " << themax(win2c, win2j, win2b);
    return 0;
}
```

## [1019 数字黑洞 20分](https://pintia.cn/problem-sets/994805260223102976/problems/994805302786899968)

### 6174作为差出现时停止，所以直接输入6174要进行运算，有1个点是这个

```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int downsort(int a1, int a2, int a3, int a4)
{
    int tmp[4] = {a1, a2, a3, a4};
    sort(tmp, tmp + 4);
    return tmp[0] + tmp[1] * 10 + tmp[2] * 100 + tmp[3] * 1000;
}

int upsort(int a1, int a2, int a3, int a4)
{
    int tmp[4] = {a1, a2, a3, a4};
    sort(tmp, tmp + 4);
    return tmp[3] + tmp[2] * 10 + tmp[1] * 100 + tmp[0] * 1000;
}

int main()
{
    int num;
    cin >> num;
    int a1, a2, a3, a4;
    a1 = num % 10;
    a2 = (num - a1) / 10 % 10;
    a3 = (num - 10 * a2 - a1) / 100 % 10;
    a4 = num / 1000;
    if (a1 == a2 && a2 == a3 && a3 == a4)
    {
        printf("%d - %d = 0000", num, num);
        return 0;
    }
    int sub1 = downsort(a1, a2, a3, a4);
    int sub2 = upsort(a1, a2, a3, a4);
    int ans = sub1 - sub2;
    printf("%04d - %04d = %04d\n", sub1, sub2, ans);
    num = ans;
    while (num != 6174)
    {
        a1 = num % 10;
        a2 = (num - a1) / 10 % 10;
        a3 = (num - 10 * a2 - a1) / 100 % 10;
        a4 = num / 1000;
        int sub1 = downsort(a1, a2, a3, a4);
        int sub2 = upsort(a1, a2, a3, a4);
        int ans = sub1 - sub2;
        printf("%04d - %04d = %04d\n", sub1, sub2, ans);
        num = ans;
    }
    return 0;
}
```

## [1020 月饼 25分](https://pintia.cn/problem-sets/994805260223102976/problems/994805301562163200)

```c++
#include<bits/stdc++.h>
using namespace::std;
struct moon
{
    double n;   //库存量
    double price;   //单价
    double total;   //总价
};

bool cmp(moon a, moon b)
{
    return a.price > b.price;   //使用sort后是由大到小排序
}

int main()
{
    moon cake[1005];
    int n;
    double d, sum = 0;
    cin >> n >> d;
    for(int i = 1; i <= n; i++)
        cin >> cake[i].n;
    for(int i = 1; i <= n; i++)
        cin >> cake[i].total;
    for(int i = 1; i <= n; i++)
        cake[i].price = cake[i].total / cake[i].n;
    sort(cake + 1, cake + n + 1, cmp);
    for(int i = 1; i <= n; ++i)
    {
        if(d >= cake[i].n)
        {
            sum += cake[i].total;
            d -= cake[i].n;
        }
        else
        {
            sum += cake[i].price * d;
            break;
        }
    }
    printf("%.2f", sum);
    return 0;
}
```

## [1021 个位数统计 15分](https://pintia.cn/problem-sets/994805260223102976/problems/994805300404535296) 秒

```cpp
#include <iostream>
using namespace std;
int cnt[10];
string n;
int main()
{
    cin >> n;
    for (int i = 0; i < n.size(); i++)
        cnt[n[i] - '0']++;
    for (int i = 0; i < 10; i++)
        if (cnt[i] != 0)
            cout << i << ":" << cnt[i] << endl;
    return 0;
}
```

## [1022 D进制的A+B 20分](https://pintia.cn/problem-sets/994805260223102976/problems/994805299301433344)

### 注意考虑转换进制数为0的情况

```cpp
#include <iostream>
#include <stack>
using namespace std;

void tenToD(long long c, long long d)
{
    stack<int> s;
    if (c == 0)
    {
        cout << 0;
        return;
    }
    while (0 < c)
    {
        s.push(c % d);
        c /= d;
    }
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}

long long a, b, c, d;
int main()
{
    cin >> a >> b >> d;
    c = a + b;
    tenToD(c, d);
}
```

## [1023 组个最小数 20 分](https://pintia.cn/problem-sets/994805260223102976/problems/994805298269634560) 秒

```cpp
#include <iostream>
using namespace std;
int num[10];
int main()
{
    for (int i = 0; i < 10; i++)
        cin >> num[i];
    int first = 0;
    for (int i = 1; i < 10; i++)
    {
        if (0 < num[i])
        {
            first = i;
            break;
        }
    }
    cout << first;
    num[first]--;
    for (int i = 0; i < 10; i++)
    {
        while (0 < num[i])
        {
            cout << i;
            num[i]--;
        }
    }
    return 0;
}
```

## [1024 科学计数法 20 分](https://pintia.cn/problem-sets/994805260223102976/problems/994805297229447168)

### 这题花了不少时间，主要在输入分割问题上

```cpp
scanf("%c%c.%[^E]E%c%d", &flag1, &front_dot, &after_dot, &flag2, &e);
```

`%[]`指读入此集合所限定的字符，例如`%[A-Z]`指接收大写字母，遇到非大写字母后停止接收

而`%[^]`指读入除此集合所限定外的字符，例如`%[^A-Z]`指接收非大写字母，遇到大写字母就停止接收

```cpp
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
```

## [1025 反转链表 25分](https://pintia.cn/problem-sets/994805260223102976/problems/994805296180871168)

给定一个常数 *K* 以及一个单链表 *L*，请编写程序将 *L* 中每 *K* 个结点反转。例如：给定 *L* 为 1→2→3→4→5→6，*K* 为 3，则输出应该为 3→2→1→6→5→4；如果 *K* 为 4，则输出应该为 4→3→2→1→5→6，即最后不到 *K* 个元素不反转。

**输入格式：**

每个输入包含 1 个测试用例。每个测试用例第 1 行给出第 1 个结点的地址、结点总个数正整数 *N* (≤105)、以及正整数 *K* (≤*N*)，即要求反转的子链结点的个数。结点的地址是 5 位非负整数，NULL 地址用 −1 表示。

接下来有 *N* 行，每行格式为：

```
Address Data Next
```

其中 `Address` 是结点地址，`Data` 是该结点保存的整数数据，`Next` 是下一结点的地址。

输出格式：

对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。

**输入样例：**

```in
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218结尾无空
```

**输出样例：**

```out
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
```

```cpp
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
```

### 辅助理解

输入示例

```in
1 6 3
1 1 2
2 2 3
3 3 4
4 4 5
5 5 6
6 6 -1
```

输出示例

```out
00003 3 00002
00002 2 00001
00001 1 00006
00006 6 00005
00005 5 00004
00004 4 -1
```

过程图示

![image-20210804231838106](https://raw.githubusercontent.com/RainGiving/PictureBed/master/img1/20210804231838.png)

## [1026 程序运行时间 15分](https://pintia.cn/problem-sets/994805260223102976/problems/994805295203598336)

```cpp
#include <iostream>
using namespace std;
int main()
{
    int c1, c2;
    cin >> c1 >> c2;
    int s = (c2 - c1) / 100;
    if (50 <= (c2 - c1) % 100)
        s++;
    int h = s / 3600;
    s = s % 3600;
    int m = s / 60;
    s = s % 60;
    printf("%02d:%02d:%02d", h, m, s);
    return 0;
}
```

## [1027 打印沙漏 20分](https://pintia.cn/problem-sets/994805260223102976/problems/994805294251491328)

```cpp
#include <iostream>
using namespace std;
int table[1000];

void make_table()
{
    table[1] = 1;
    int new_flood = 3;
    for (int i = 2; i < 1000; i++)
    {
        table[i] = table[i - 1] + 2 * new_flood;
        new_flood += 2;
    }
}

int main()
{
    make_table();
    int num;
    char sign;
    cin >> num >> sign;
    int cnt = 0;
    while (true)
        if (num < table[++cnt])
            break;
    cnt--;
    for (int j = cnt; 0 < j; j--)
    {
        int charnum = 1 + 2 * (j - 1), spacenum = 1 + 2 * (cnt - 1) - charnum;
        for (int k = 0; k < spacenum / 2; k++)
            cout << " ";
        for (int k = 0; k < charnum; k++)
            cout << sign;
        cout << endl;
    }
    for (int j = 2; j <= cnt; j++)
    {
        int charnum = 1 + 2 * (j - 1), spacenum = 1 + 2 * (cnt - 1) - charnum;
        for (int k = 0; k < spacenum / 2; k++)
            cout << " ";
        for (int k = 0; k < charnum; k++)
            cout << sign;
        cout << endl;
    }
    cout << num - table[cnt];
    return 0;
}
```

