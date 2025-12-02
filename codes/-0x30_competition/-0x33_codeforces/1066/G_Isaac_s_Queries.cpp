#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

using a2 = std::array<int, 2>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

const int B = 30;

struct dsu {
    std::vector<int> parents;
    std::vector<int> sizes;
    dsu(int n) {
        parents.resize(n);
        iota(parents.begin(), parents.end(), 0);
        sizes.resize(n, 1);
    }
    int get_root(int u) {
        return parents[u] == u ? u : parents[u] = get_root(parents[u]);
    }
    bool merge(int u, int v) {
        int a = get_root(u);
        int b = get_root(v);
        if (a == b) return 0;
        if (sizes[a] > sizes[b]) std::swap(a, b);
        parents[a] = b;
        sizes[b] += sizes[a];
        return 1;
    }
};

void solve() {
    int n;std::cin >> n;
    std::vector<dsu> D(B, dsu(2 * (n + 1)));
    std::map<a2, int> map;

    auto same = [&](int L, int R, int bit) {
        D[bit].merge(L, R);
        D[bit].merge(L + n + 1, R + n + 1);
        };

    auto diff = [&](int L, int R, int bit) {
        D[bit].merge(L, R + n + 1);
        D[bit].merge(L + n + 1, R);
        };

    auto query = [&](int L, int R) {
        if (L > R) std::swap(L, R);
        if (map.count({ L, R })) return map[{L, R}];
        std::cout << "? " << L + 1 << ' ' << R << std::endl;
        int x; std::cin >> x;
        for (int i = x + 1;i < B;++i) same(L, R, i);
        if (x >= 0) diff(L, R, x);
        return map[{L, R}] = x;
        };

    auto work = [&](this auto&& work, std::vector<int> idxs, int bit) {
        if (idxs.size() <= 1 || bit < 0) return;
        int m = idxs.size();
        int l = idxs.front();
        int r = idxs.back();
        query(l, r);
        for (int i = 1;i < m - 1;++i) {
            query(idxs[i], idxs[i] - l < r - idxs[i] ? r : l);
        }
        std::vector<int> zeros, ones;
        for (int i = 0;i < idxs.size();++i) {
            if (D[bit].get_root(idxs[i]) == D[bit].get_root(idxs[0])) {
                zeros.push_back(idxs[i]);
            }
            else {
                ones.push_back(idxs[i]);
            }
        }
        work(zeros, bit - 1);
        work(ones, bit - 1);
        };

    std::vector<int> idxs(n + 1);
    std::iota(idxs.begin(), idxs.end(), 0);
    work(idxs, B - 1);

    std::cout << "! ";
    for (int i = 0;i <= n; ++i) {
        for (int j = i + 1;j <= n;++j) {
            int ans = B - 1;
            while (ans >= 0 && D[ans].get_root(i) == D[ans].get_root(j)) ans--;
            std::cout << ans << ' ';
        }
        std::cout << std::endl;
    }
}

signed main() {
    int t;std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}