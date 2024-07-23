#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;

struct team
{
    std::string name;
    int num;
    int time;
};


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;std::cin >> n;
    std::set<std::string> st1, st2;
    std::vector<team> t1(n);
    for (auto& [s, n, t] : t1)std::cin >> s >> n >> t, st1.insert(s);
    int m;std::cin >> m;
    std::vector<team> t2(m);
    for (auto& [s, n, t] : t2)std::cin >> s >> n >> t, st2.insert(s);
    std::sort(t1.begin(), t1.end(), [&](auto a, auto b) {
        if (a.num == b.num)return a.time < b.time;
        return a.num > b.num;
        });
    std::sort(t2.begin(), t2.end(), [&](auto a, auto b) {
        if (a.num == b.num)return a.time < b.time;
        return a.num > b.num;
        });
    int ans = inf, cnt = 0;
    for (int i = 0;i < n;++i) {
        if (t1[i].name == "lzr010506") {
            ans = std::min(ans, cnt + 1);
            break;
        }
        if (!st2.count(t1[i].name))cnt++;
    }
    cnt = 0;
    for (int i = 0;i < m;++i) {
        if (t2[i].name == "lzr010506") {
            ans = std::min(ans, cnt + 1);
            break;
        }
        if (!st1.count(t2[i].name))cnt++;
    }
    std::cout << ans;
    return 0;
}