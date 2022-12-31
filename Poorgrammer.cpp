#include <bits/stdc++.h>
using namespace std;

long long int arr[200005];
long long int n, m;

long long int cal(int day)
{
    long long int sum = 0;
    for (int i = 0; i < day; i++)
    {
        sum += arr[i];
    }
    long long int nb = 0, times = 1;
    for (int i = day; i < n; i++)
    {
        nb++;
        if (arr[i] - times > 0)
            sum += (arr[i] - times);
        if (nb == day)
            times++, nb = 0;
    }
    return sum;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        long long int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long int l = 1, r = n + 1, ans = -1;
        while (l < r)
        {
            long long int mid = (l + r) / 2;
            if (cal(mid) >= m)
                ans = mid, r = mid;
            else
                l = mid + 1;
        }
        cout << ans << "\n";
    }
}