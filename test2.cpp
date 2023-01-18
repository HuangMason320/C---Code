#include <bits/stdc++.h>
using namespace std;

int m[2010][26];
int visited[2010];
vector<string> s;
int n;

void dfs(int now)
{
    visited[now] = 1;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 1)
            continue;
        for (int j = 0; j < 26; j++)
        {
            if (m[i][j] == 1 && m[now][j] == 1)
            {
                dfs(i);
                break;
            }
        }
    }
}
void reset()
{
    memset(m, 0, sizeof(m));
    s.clear();
    memset(visited, 0, sizeof(visited));
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        reset();
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string tmp;
            cin >> tmp;
            s.push_back(tmp);
            for (auto c : tmp)
            {
                m[i][c - 'a'] = 1;
            }
        }
        int group = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 1)
                continue;
            dfs(i);
            group++;
        }
        cout << group << endl;
    }
}