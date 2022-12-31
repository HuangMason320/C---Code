// I got a perfect body
#include <bits/stdc++.h>
using namespace std;

int arr[300000], pre[300000];

int cmp(const void *a, const void *b)
{
    int *A = (int *)a;
    int *B = (int *)b;
    return *(int *)A - *(int *)B;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        pre[0] = 0;
        int n, p, k, ans = 0;
        cin >> n >> p >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        qsort(arr + 1, n, sizeof(int), cmp);
        for (int i = 1; i <= n; i++)
        {
            if (i >= k)
                pre[i] = arr[i] + pre[i - k];
            else
                pre[i] = arr[i] + pre[i - 1];
        }
        for (int i = 1; i <= n; i++)
        {
            if (p >= pre[i])
                ans = i;
        }
        cout << ans << "\n";
    }
}