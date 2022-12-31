// Timelines jumping left and right
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct T_mods
{
    T operator()(const T &data1, const T &val, size_t size)
    {
        return data1 + val * size;
    }
};
template <class T>
struct T_merges
{
    T operator()(const T &data1, const T &data2)
    {
        return data1 + data2;
    }
};

template <class T>
struct T_modm
{
    T operator()(const T &data1, const T &val, size_t size)
    {
        return data1 + val;
    }
};
template <class T>
struct T_mergem
{
    T operator()(const T &data1, const T &data2)
    {
        return (data1 > data2) ? data1 : data2;
    }
};

int main()
{
    int n, q;
    cin >> n;
    vector<long long int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    SegmentTree<long long int, T_mods<long long int>, T_merges<long long int>> sts(a);
    SegmentTree<long long int, T_modm<long long int>, T_mergem<long long int>> stm(a);
    cin >> q;
    while (q--)
    {
        string ins;
        int L, R, V;
        cin >> ins;
        if (ins == "modify")
        {
            cin >> L >> R >> V;
            sts.modify(L, R, V);
            stm.modify(L, R, V);
        }
        else if (ins == "sum")
        {
            cin >> L >> R;
            cout << sts.query(L, R) << endl;
        }
        else
        {
            cin >> L >> R;
            cout << stm.query(L, R) << endl;
        }
    }
}