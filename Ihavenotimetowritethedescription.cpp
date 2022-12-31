// I have no time to write the description.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        long long int dp[k + 5][n + 5] = {0}, a[n + 5], pre[n + 5] = {0};
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == 1)
                {
                    dp[i][j] = pre[j];
                    continue;
                }
                long long int temp = 0;
                for (int l = i - 1; l <= j; l++)
                {
                    long long int sum = pre[j] - pre[l - 1];
                    if (temp == 0)
                        temp = max(dp[i - 1][l - 1], sum);
                    else
                        temp = min(max(dp[i - 1][l - 1], sum), temp);
                }
                dp[i][j] = temp;
            }
        }
        cout << dp[k][n] << "\n";
    }
}