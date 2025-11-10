#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

#define int long long

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;
using a10 = std::array<int, 10>;

const int dx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy[8] = { 0, 1, 0, -1, -1, 1, -1, 1 };
const int N = 255;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
const i64 INF = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n, k;   std::cin >> n >> k;
    std::vector adj(n + 1, std::vector<int>());
    std::bitset<N> base1[N];
    std::bitset<N> base2[N];
    std::vector<std::bitset<N>> path; path.reserve(n);
    std::vector<int> res(N, -1);
    int rank = 0;

    for (int i = 1;i <= n - 1;i++) {
        int u, v;   std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto insert1 = [&](std::bitset<N> cur) ->bool {
        for (int i = n; i >= 1; i--) {
            if (!cur[i]) continue;
            if (!base1[i].any()) {
                base1[i] = cur;
                rank++;
                return true;
            }
            cur ^= base1[i];
        }
        return false;
        };

    auto insert2 = [&](std::bitset<N> cur, i64 x) ->bool {
        for (int i = n; i >= 1; i--) {
            if (!cur[i]) continue;
            if (!base2[i].any()) {
                // std::cout << i << ' ' << x << "\n";
                base2[i] = cur;
                res[i] = x;
                return true;
            }
            cur ^= base2[i];
            x ^= res[i];
        }
        return false;
        };

    std::bitset<N> v1;
    v1.set(1);
    insert1(v1);
    insert2(v1, 0);
    std::vector<pii> q;     //有效询问
    bool f = 0;
    assert(res[1] == 0);

    std::bitset<N> line; int root = -1;
    auto work = [&](this auto&& self, int u, int p, int dep) {
        line[u] = 1;
        if (dep == k) {
            if (u > root) {
                if (insert1(line)) {
                    q.push_back({ root, u });
                    path.push_back(line);
                }
                else if (!f) {
                    path.push_back(line);
                    q.push_back({ root, u });
                    f = 1;
                }
            }
            line[u] = 0;
            return;
        }
        for (auto v : adj[u]) if (v != p) {
            self(v, u, dep + 1);
        }
        line[u] = 0;
        };

    for (int i = 1;i <= n;i++) {
        root = i;
        work(i, -1, 0);
    }

    if (rank == n) {
        std::cout << "YES" << std::endl;

        std::cout << "? " << q.size() << " ";
        for (int i = 0;i < q.size();i++) {
            std::cout << q[i].first << " " << q[i].second << " ";
        }
        std::cout << std::endl;

        for (int i = 0;i < q.size();++i) {
            int x;std::cin >> x;
            insert2(path[i], x);
        }

        for (int i = 1;i <= n;++i) {
            for (int j = i + 1;j <= n;++j) {
                if (base2[j][i]) res[j] ^= res[i];
            }
        }

        std::cout << "! ";
        for (int i = 2;i <= n;++i) {
            std::cout << res[i] << ' ';
        }
        std::cout << std::endl;
    }
    else std::cout << "NO" << std::endl;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    while (t--) {
        solve();
        // std::cout << '\n';
    }
}