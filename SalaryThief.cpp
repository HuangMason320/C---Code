#include <bits/stdc++.h>
using namespace std;
#define MOD (int)(1e9 + 7)

int t, x;
long long l, add;
string s, tmp;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> x >> s;
        l = s.size();
        add = 0;
        int left = s[0] - '0';
        for (int i = 1; i <= x; i++)
        {
            add = ((l - i + MOD) % MOD) * left;
            l = (i + add % MOD) % MOD;
            if (s.size() <= x)
            {
                tmp = s.substr(i);
                if (left > 1)
                {
                    for (int j = 0; j < left - 1; j++)
                        s += tmp;
                }
            }
            left = s[i] - '0';
        }
        cout << l << endl;
    }
}