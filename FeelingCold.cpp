// Feeling cold
#include <bits/stdc++.h>
using namespace std;

struct comp
{
    bool operator()(const string &s1, const string &s2) const
    {
        if (s1.length() != s2.length())
            return s1.length() < s2.length();
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] != s2[i])
                return s1[i] < s2[i];
        }
        return false;
    }
};

int main()
{
    map<string, int, comp> num;
    vector<string> D;
    int n, total = 0;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "insert")
        {
            string tmp;
            cin >> tmp;
            D.push_back(tmp);
            if (num.count(tmp))
                num[tmp]++;
            else
                num[tmp] = 1;
            total++;
        }
        else if (s == "min" && total != 0)
        {
            cout << (*num.begin()).first << endl;
        }
        else if (s == "max" && total != 0)
        {
            cout << (*num.rbegin()).first << endl;
        }
        else if (s == "amount")
        {
            string tmp;
            cin >> tmp;
            if (num.count(tmp))
                cout << num[tmp] << endl;
            else
                cout << "0\n";
        }
        else if (s == "find")
        {
            int tmp;
            cin >> tmp;
            if (tmp < total)
                cout << D[tmp - 1] << endl;
        }
    }
}