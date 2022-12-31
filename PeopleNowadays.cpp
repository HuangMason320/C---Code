#include <bits/stdc++.h>
using namespace std;

set<pair<int, string>> society;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string order;
        cin >> order;
        if (order == "born")
        {
            string s;
            int age;
            cin >> s >> age;
            society.insert({age, s});
        }
        else if (order == "find")
        {
            string s;
            int age;
            cin >> s >> age;
            if (society.find({age, s}) == society.end())
                cout << "NO\n";
            else
                cout << "YES\n";
        }
        else if (order == "kill")
        {
            string s;
            int age;
            cin >> s >> age;
            society.erase({age, s});
        }
        else
        {
            if (society.empty())
                continue;
            else
                cout << (*society.begin()).second << " " << (*society.begin()).first << "\n";
        }
    }
}