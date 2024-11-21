#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 2e5;
const int MAXN = 2e5 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

std::vector<int> yz[MAXN];

void init() {
    for (int i = 1;i <= N;++i) {
        for (int j = i;j <= N;j += i) {
            yz[j].push_back(i);
        }
    }
}

void solve() {
    int n, q;std::cin >> n >> q;
    std::vector<int> a(n), cnt(n + 1), ccnt(n + 1);
    ccnt[0] = n;
    for (int& x : a)std::cin >> x;
    int sz = 0;
    auto insert = [&](int x) {
        sz++;
        for (auto y : yz[x]) {
            ccnt[cnt[y]]--;
            cnt[y]++;
            ccnt[cnt[y]]++;
        }
        };
    auto del = [&](int x) {
        sz--;
        for (auto y : yz[x]) {
            ccnt[cnt[y]]--;
            cnt[y]--;
            ccnt[cnt[y]]++;
        }
        };
    for (int i = 0;i < n - 1;++i) {
        if (a[i] > a[i + 1])
            insert(i + 1);
    }

    std::cout << ccnt[sz] << '\n';
    for (int i = 0;i < q;++i) {
        int p, v;std::cin >> p >> v;p--;
        if (p)if (a[p - 1] > a[p])del(p);
        if (p != n - 1)if (a[p] > a[p + 1])del(p + 1);
        a[p] = v;
        if (p)if (a[p - 1] > a[p])insert(p);
        if (p != n - 1)if (a[p] > a[p + 1])insert(p + 1);
        std::cout << ccnt[sz] << '\n';
    }

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    init();
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}