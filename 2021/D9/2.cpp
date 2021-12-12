#include <bits/stdc++.h>

using namespace std;

#define vtc vector

int dfs(vtc<vtc<int>> &v, vtc<vtc<bool>> &isDone, int x, int y)
{
    if (!(y >= 0 and y < v.size() and x >= 0 and x < v[y].size()))
        return 0;
    if (isDone[y][x] or v[y][x] == 9)
        return 0;
    isDone[y][x] = true;
    int sum = 0;
    sum += dfs(v, isDone, x-1, y);
    sum += dfs(v, isDone, x+1, y);
    sum += dfs(v, isDone, x, y-1);
    sum += dfs(v, isDone, x, y+1);
    return sum + 1;
}

int main()
{
    vtc<vtc<int>> v;
    vtc<vtc<bool>> isDone;
    string s;
    while (getline(cin, s))
    {
        vtc<int> temp;
        vtc<bool> isDonetmp;
        for (auto &c : s)
        {
            temp.push_back(c - '0');
            isDonetmp.push_back(false);
        }
        isDone.emplace_back(isDonetmp);
        v.emplace_back(temp);
    }
    int sum = 0;
    vtc<int> res;

    for (int y = 0; y < v.size(); y++)
    {
        for (int x = 0; x < v[y].size(); x++)
        {
            if (isDone[y][x])
                continue;
            int c = dfs(v, isDone, x, y);
            if (c != 0)
                res.push_back(c);
        }
    }
    sort(res.begin(), res.end());
    int last = res.size();
    if (last >= 3)
        cout << res[last - 1] * res[last - 2] * res[last - 3] << endl;
}