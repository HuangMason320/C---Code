// Motto Hayaku(I2P2 Bouns 4)
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int ind, val;
ll n, x, A, B, m, ans;
vector<ll> mini, maxi((int)1e5 + 5);
vector<pair<ll, int>> arr;
pair<ll, ll> step, tmp;
pair<ll, ll> getpoint(ll m1, int l, vector<ll> minin)
{
    auto ans_tmp = upper_bound(minin.begin() + 1, minin.end(), m1);
    pair<ll, ll> temp = {(arr[ans_tmp - minin.begin() - 1].first) * B + A * (l + 1), ans_tmp - minin.begin() - 1};
    return temp;
}

bool cmp(pair<ll, int> a, pair<ll, int> b)
{
    return a.second < b.second;
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> x >> A >> B >> m;
    vector<ll> mini(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> val;
        arr.push_back(pair(val, i));
    }
    sort(arr.begin(), arr.end());
    for (int i = 1; i <= n; i++)
        maxi[i] = x - arr[i - 1].first;
    for (int i = n - 1; i > 0; i--)
        maxi[i] += maxi[i + 1];
    for (int i = 1; i < n; i++)
        mini[i] = (arr[i].first - arr[i - 1].first) * i;
    for (int i = 1; i <= n; i++)
        mini[i] += mini[i - 1];
    if (maxi[1] < m)
    {
        cout << B * x + A * n << endl;
        for (int i = 0; i < n; i++)
            cout << x << " ";
    }
    else
    {
        step.first = n;
        for (int i = n; i > 0; i--)
        {
            if (maxi[i] > m)
                break;
            else
            {
                tmp = getpoint(m - maxi[i], n - i, mini);
                if (tmp.first > ans)
                {
                    ans = tmp.first;
                    step.first = i;
                    step.second = tmp.second;
                }
            }
        }
        for (int i = step.first - 1; i < n; i++)
            arr[i].first = x;
        ind = step.second;
        for (int i = 0; i < ind; i++)
            arr[i].first = arr[ind].first;
        sort(arr.begin(), arr.end(), cmp);
        cout << ans << endl;
        for (int i = 0; i < n; i++)
            cout << arr[i].first << " ";
    }
    return 0;
}