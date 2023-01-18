#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5e4 + 1;
long long int arr[MAX_N * 2], sum[MAX_N * 2];
long long int ans = 0;

void reset()
{
    memset(arr, 0, sizeof(arr));
    memset(sum, 0, sizeof(sum));
    ans = 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        reset();
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int i = a; i <= b; i++)
        {
            arr[i + b]++;
            arr[i + c + 1]--;
        }
        for (int i = a; i <= b + c + 1; i++)
        {
            arr[i] += arr[i - 1];
        }
        for (int i = a; i <= 1.5 * d; i++)
        {
            sum[i] = sum[i - 1] + arr[i];
        }
        for (int i = c; i <= d; i++)
        {
            ans += (sum[(int)ceil(1.5 * i) - 1] - sum[i]);
        }
        cout << ans << endl;
    }
}