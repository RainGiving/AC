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