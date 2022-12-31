#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q, t;
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        int ans = -1, L[q], R[q], pre[n + 1] = {0}, state[n + 1] = {0};
        for (int i = 0; i < q; i++)
        {
            cin >> L[i] >> R[i];
            for (int j = L[i]; j <= R[i]; j++)
            {
                state[j]++;
            }
        }
        for (int i = 0; i < q; i++)
        {
            int num = 0, min = n + 5;
            for (int j = L[i]; j <= R[i]; j++)
            {
                state[j]--;
            }
            pre[0] = 0;
            for (int z = 1; z <= n; z++)
            {
                if (state[z] == 1)
                {
                    pre[z] = state[z] + pre[z - 1];
                }
                else
                    pre[z] = pre[z - 1];
                if (state[z] > 0)
                    num++;
            }
            for (int j = 0; j < q; j++)
            {
                if (i != j)
                {
                    if (pre[R[j]] - pre[L[j] - 1] < min)
                        min = pre[R[j]] - pre[L[j] - 1];
                }
            }
            for (int j = L[i]; j <= R[i]; j++) // Add the num of i
            {
                state[j]++;
            }
            if (num - min > ans) // Best Ans
            {
                ans = num - min;
            }
        }
        cout << ans << "\n";
    }
}