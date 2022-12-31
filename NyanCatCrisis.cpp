#include <bits/stdc++.h>
using namespace std;

int t, n, r, k, tmp;
bool dis(pair<int, int> a, pair<int, int> b)
{
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second) <= r * r;
}
int dfs(vector<pair<int, int>> &arr, vector<bool> &visit, int num)
{
    int size = 1;
    visit[num] = true;
    for (int i = 0; i < n; i++)
    {
        if (!visit[i] && dis(arr[i], arr[num]))
        {
            size += dfs(arr, visit, i);
        }
    }
    return size;
}
int main()
{
    cin >> t;
    while (t--)
    {
        int ans1 = 0, ans2 = 0;
        cin >> n >> r >> k;
        vector<pair<int, int>> arr(n);
        vector<bool> visit(n, false);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].first >> arr[i].second;
        }
        for (int i = 0; i < n; i++)
        {
            if (!visit[i])
            {
                if (dfs(arr, visit, i) >= k)
                    ans2++;
                else
                    ans1++;
            }
        }
        cout << ans1 << " " << ans2 << endl;
    }
}