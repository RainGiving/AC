#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
const int N = 100010;
vector<PII> segs;
int n;

void merge(vector<PII> &segs)
{
    if(segs.size() == 0)    return;
    vector<PII> res;
    sort(segs.begin(), segs.end());
    int st = segs[0].first, ed = segs[0].second;
    for(int i = 1; i < segs.size(); i++)
        if(ed < segs[i].first)
        {
            res.push_back({st, ed});
            st = segs[i].first, ed = segs[i].second;
        }
        else ed = max(ed, segs[i].second);
    res.push_back({st, ed});
    segs = res;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        segs.push_back({l, r});
    }
    merge(segs);
    cout << segs.size() << endl;
    return 0;
}