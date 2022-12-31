#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5e4 + 1;
long long tmp[MAX_N * 2];
long long suf[MAX_N * 2];
int t, a, b, c, d;

void reset()
{
    memset(tmp, 0, sizeof(tmp));
    memset(suf, 0, sizeof(suf));
}
int main()
{
    cin >> t;
    while (t--)
    {
        reset();
        long long int ans = 0;
        cin >> a >> b >> c >> d;
        for (int i = a; i <= b; i++)
            tmp[i + b]++, tmp[i + c + 1]--;
        for (int i = a + b; i < b + c + 1; i++)
            tmp[i] += tmp[i - 1];
        for (int i = b + c; i > 0; i--)
            suf[i] = suf[i + 1] + tmp[i];
        for (int i = c; i <= d; i++)
            ans += suf[i + 1];
        cout << ans << endl;
    }
}