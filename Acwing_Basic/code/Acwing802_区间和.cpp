#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


typedef pair<int, int> PII;
//n次操作一共可能用到n个位置，m次询问[l, r]一共可能用到2m个位置，n + 2m <= 3e5
const int N = 300010;
int a[N], s[N]; 
int n, m;
vector<int> alls;
vector<PII> add, query; //add需要位置x和加数c，query需要左右边界l和r

int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(x <= alls[mid])  r = mid;
        else                l = mid + 1;
    }
    return r + 1;   //配合求前缀和，使a的索引从1开始
}

int main()
{
    cin >> n >> m;
    //读入add操作所有数据
    for(int i = 0; i < n; i++)
    {
        int x, c;
        scanf("%d%d", &x, &c);
        add.push_back({x, c});
        alls.push_back(x);  //出现的位置存入alls
    }
    //读入query操作所有数据
    for(int i = 0; i < m; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        query.push_back({l, r});
        alls.push_back(l);  //出现的位置存入alls
        alls.push_back(r);  //出现的位置存入alls
    }
    sort(alls.begin(), alls.end()); //排序
    alls.erase(unique(alls.begin(), alls.end()), alls.end());    //去重
    
    for(int i = 0; i < add.size(); i++)
        a[find(add[i].first)] += add[i].second; //对a执行add操作
        
    for(int i = 1; i <= alls.size(); i++)    //求a的前缀和
        s[i] = s[i - 1] + a[i];
        
    for(int i = 0; i < query.size(); i++)   //处理询问
    {
        int l = find(query[i].first), r = find(query[i].second);
        printf("%d\n", s[r] - s[l - 1]);
    }
  
    return 0;
}