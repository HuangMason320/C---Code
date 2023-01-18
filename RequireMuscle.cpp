#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[10], b[10];
stack<int> barbell;
int weight;
int ans;

void solve(int day, int steps, int ban_act)
{
    if (steps >= ans)
        return;
    if (day == n + 1)
    {
        ans = steps;
        return;
    }
    if (weight == a[day])
        solve(day + 1, steps, 0);

    for (int i = 1; i <= m; ++i)
        if (ban_act != b[i] && weight + b[i] <= a[day])
        {
            barbell.push(b[i]);
            weight += b[i];
            solve(day, steps + 1, -1);
            barbell.pop();
            weight -= b[i];
        }

    if (ban_act != -1 && !barbell.empty())
    {
        int tmp = barbell.top();
        barbell.pop();
        weight -= tmp;
        solve(day, steps + 1, tmp);
        barbell.push(tmp);
        weight += tmp;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        while (!barbell.empty())
            barbell.pop();
        weight = 0;
        ans = (int)1e9;

        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        for (int i = 1; i <= m; ++i)
            cin >> b[i];

        solve(1, 0, 0);
        cout << ans << endl;
    }
    return 0;
}