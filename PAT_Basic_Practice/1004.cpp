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