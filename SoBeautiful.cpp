#include <bits/stdc++.h>
using namespace std;

int n;
map<int, map<char, int>> bucket;
pair<int, char> arr;
pair<int, int> ans;
string str;

int main()
{
    ans.first = 0, ans.second = 0;
    cin >> n;
    while (n--)
    {
        cin >> str;
        arr.first = 0;
        for (auto i = str.begin(); i != str.end(); i++)
        {
            if (*i == 'a' || *i == 'e' || *i == 'i' || *i == 'o' || *i == 'u')
            {
                arr.first++;
                arr.second = *i;
            }
        }
        bucket[arr.first][arr.second]++;
    }
    for (auto i : bucket)
    {
        int tmp = 0;
        for (auto j : i.second)
        {
            ans.first += bucket[i.first][j.first] / 2;
            tmp += bucket[i.first][j.first] % 2;
        }
        ans.second += tmp / 2;
    }
    if (ans.first < ans.second)
        cout << ans.first << endl;
    else
        cout << (ans.first + ans.second) / 2 << endl;
    return 0;
}