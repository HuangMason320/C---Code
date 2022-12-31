#include <bits/stdc++.h>
using namespace std;

set<pair<string, int>> society;

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
            society.insert({s, age});
        }
        else if (order == "find")
        {
            string s;
            int age;
            if (society.find({s, age}) == society.end())
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
        else if (order == "kill")
        {
            string s;
            int age;
            society.erase({s, age});
        }
        else
        {
            if (society.empty())
                continue;
            else
                cout << (*society.begin()).first << " " << (*society.begin()).second << endl;
        }
    }
}