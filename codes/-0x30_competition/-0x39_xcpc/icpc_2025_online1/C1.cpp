#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace __gnu_pbds;

using i64 = long long;
using ld = long double;

using a2 = std::array<int, 2>;
using a3 = std::array<i64, 3>;
using pii = std::pair<int, int>;

using rdtree = tree<a2, null_type, std::less<a2>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e6;
const int inf = 1e9;
const i64 INF = 1e18;
const int mod = 1e9 + 7;

struct Fenwick
{
    std::vector<i64> w;
    int n;
    Fenwick(int n) : n(n), w(n + 1) {}
    void add(int x, i64 v)
    {
        for (; x <= n; x += x & -x)
        {
            w[x] += v;
        }
    }
    i64 query(int x)
    {
        i64 res = 0;
        for (; x; x -= x & -x)
        {
            res += w[x];
        }
        return res;
    }
};

void sovle()
{
    int m, n;
    std::cin >> m >> n;
    std::vector<a2> info(m);
    std::vector<int> rank;
    for (auto &[x, y] : info)
    {
        std::cin >> x >> y;
        rank.push_back(x);
        rank.push_back(y);
    }
    std::ranges::sort(info.begin(), info.end(), [&](a2 &a, a2 &b)
                      { if(a[1] - a[0] == b[1] - b[0]) return a[0] < b[0];
                        return a[1] - a[0] < b[1] - b[0]; });
    std::ranges::sort(rank);
    rank.erase(std::unique(rank.begin(), rank.end()), rank.end());
    int k = rank.size();
    Fenwick fwl(k + 1), fwr(k + 1);
    int ans = 0;
    for (int i = 0; i < m; ++i)
    {
        auto [l, r] = info[i];
        int L = std::lower_bound(rank.begin(), rank.end(), l) - rank.begin() + 1;
        int R = std::lower_bound(rank.begin(), rank.end(), r) - rank.begin() + 1;
        int cnt = ans - fwl.query(L - 1) - (ans - fwr.query(R));
        if (cnt >= r - l)
            continue;
        fwl.add(L, 1);
        fwr.add(R, 1);
        ans++;
        std::cout << l << ' ' << r << '\n';
    }
    std::cout << n - ans;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    // rdtree test;
    // test.insert({2, 0});
    // test.insert({4, 0});
    // std::cout << test.order_of_key({5, 1});
    int t = 1;
    std::cin >> t;
    while (t--)
    {
        sovle();
        std::cout << '\n';
    }
}