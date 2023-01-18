#include <bits/stdc++.h>
using namespace std;

struct comp
{
    bool operator()(const string &s1, const string &s2) const
    {
        if (s1.length() != s2.length())
            return s1.length() < s2.length();
        for (int i = 0; i < s1.length();i++)
        {
            if (s1[i] != s2[i])
                return s1[i] < s2[i];
        }
        return false;
    }
};

int
main()
{
    map<string, int, comp> num;
    vector<string> D;
    int n;
    int total = 0;
    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;
        if (str == "insert")
        {
            string s;
            cin >> s;
            D.push_back(s);
            if (num.count(s))
                num[s]++;
            else
                num[s] = 1;
            total++;
        }
        else if (str == "min" && total != 0)
        {
            cout << (*num.begin()).first << endl;
        }
        else if (str == "max" && total != 0)
        {
            cout << (*num.rbegin()).first << endl;
        }
        else if (str == "find")
        {
            int tmp;
            cin >> tmp;
            if (tmp < total)
                cout << D[tmp - 1] << endl;
        }
        else if (str == "amount")
        {
            string tmp;
            cin >> tmp;
            if (num.count(tmp))
                cout << num[tmp] << endl;
            else
                cout << "0\n";
        }
    }
}