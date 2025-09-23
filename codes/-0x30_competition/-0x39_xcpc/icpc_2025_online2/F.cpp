#include <bits/stdc++.h>
using namespace std;
using pii = std::pair<int, int>;
using i64 = long long;
using a3 = std::array<int, 3>;
using ld = long double;

const int mod = 1e9 + 7;

i64 qpow(i64 x, i64 b)
{
    i64 ret = 1;
    while (b)
    {
        if (b & 1)
            ret = ret * x % mod;
        b >>= 1;
        x = x * x % mod;
    }
}

struct NodeThin
{
    i64 val, cost;
};

struct NodeHeavy
{
    i64 idx, p, q, x, y;
};

void slove()
{
    i64 n, A, B;
    cin >> n >> A >> B;
    vector<NodeHeavy> a(n);
    for (int i = 0; i < n; i++)
        a[i].idx = i;
    for (auto &x : a)
        cin >> x.p;
    for (auto &x : a)
        cin >> x.q;
    for (auto &x : a)
        cin >> x.x;
    for (auto &x : a)
        cin >> x.y;
    vector<NodeThin> zoneA, zoneB;
    zoneA.reserve(n);
    zoneB.reserve(n);
    for (auto &x : a)
    {
        zoneA.emplace_back(x.p, x.x);
        zoneB.emplace_back(x.q, x.y);
    }
    ranges::sort(zoneA, {}, &NodeThin::val);
    ranges::sort(zoneB, {}, &NodeThin::val);
    int cntA = upper_bound(zoneA.begin(), zoneA.end(), A, [](NodeThin &a, NodeThin &b)
                           { return a.val, b.val; }) -
               zoneA.begin();
    int cntB = upper_bound(zoneB.begin(), zoneB.end(), B, [](NodeThin &a, NodeThin &b)
                           { return a.val, b.val; }) -
               zoneB.begin();
    if (cntA == 0 || zoneA[cntA] != A || cntB == 0 || zoneB[cntB] != B)
    {
        cout << -1;
        return;
    }
    // 统计A和B需要的被提升的数的数量
    // 提取可被提升的数的cost到三个优先队列，仅A，仅B，同时A&B
    // 比较A&B.top和A.top+B.top，然后取小的，cost累计到ans
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    // std::cin >> t;
    while (t--)
    {
        slove();
        std::cout << '\n';
    }
}