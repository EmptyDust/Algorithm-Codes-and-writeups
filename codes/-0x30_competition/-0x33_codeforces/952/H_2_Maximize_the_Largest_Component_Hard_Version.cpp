#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
using pii = std::pair<int, int>;
using a4 = std::array<int, 4>;

template<typename T>
struct Fenwick {
    int n;
    std::vector<T> a;

    Fenwick(int n_ = 0) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        a.assign(n + 5, T{});
    }

    void add(int x, const T& v) {
        x++;
        for (int i = x; i <= n; i += i & -i) {
            a[i] = a[i] + v;
        }
    }

    T sum(int x) {
        x++;
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i];
        }
        return ans;
    }

    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }

    int select(const T& k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i] <= k) {
                x += i;
                cur = cur + a[x];
            }
        }
        return x;
    }
};

void solve() {
    int n, m;std::cin >> n >> m;
    std::vector<std::vector<int>> map(n, std::vector<int>(m)), vis(map);
    for (int i = 0;i < n;++i) {
        std::string s;
        std::cin >> s;
        for (int j = 0;j < m;++j) {
            map[i][j] = s[j] == '#';
        }
    }
    pii dir[4] = { {1,0},{-1,0},{0,1},{0,-1} };
    auto vaild = [&](int x, int y) {return 0 <= x && x < n && 0 <= y && y < m;};
    std::vector<a4> vt;
    std::vector<int> cs(1, 0);
    std::vector<int> x_sum(n + 1, 0), y_sum(m + 1, 0);
    for (int i = 0;i < n;++i) {
        for (int j = 0;j < m;++j)if (!vis[i][j] && map[i][j]) {
            int id = cs.size();
            cs.push_back(0);
            std::queue<pii> q;
            q.push({ i,j });

            int x_min = inf, x_max = 0, y_min = inf, y_max = 0;
            while (q.size()) {
                auto [x, y] = q.front();
                q.pop();
                if (vis[x][y])continue;
                vis[x][y] = id;

                x_min = std::min(x, x_min);
                y_min = std::min(y, y_min);
                x_max = std::max(x, x_max);
                y_max = std::max(y, y_max);

                cs.back()++;
                for (int k = 0;k < 4;++k) {
                    int nx = x + dir[k].first;
                    int ny = y + dir[k].second;
                    if (vaild(nx, ny) && map[nx][ny] && !vis[nx][ny]) {
                        q.push({ nx,ny });
                    }
                }
            }

            x_min = std::max(0, x_min - 1);
            x_max = std::min(n, x_max + 2);
            y_min = std::max(0, y_min - 1);
            y_max = std::min(m, y_max + 2);//[min,max)
            vt.push_back({ x_min,y_min,y_max,cs.back() });
            vt.push_back({ x_max,y_min,y_max,-cs.back() });
            x_sum[x_min] += cs.back();
            x_sum[x_max] -= cs.back();
            y_sum[y_min] += cs.back();
            y_sum[y_max] -= cs.back();
        }
    }
    for (int i = 0;i < n;++i)
        x_sum[i] += (i == 0 ? 0 : x_sum[i - 1]);
    for (int j = 0;j < m;++j)
        y_sum[j] += (j == 0 ? 0 : y_sum[j - 1]);
    for (int i = 0;i < n;++i)
        for (int j = 0;j < m;++j)
            if (!map[i][j]) {
                x_sum[i]++;
                y_sum[j]++;
            }

    std::ranges::sort(vt);
    Fenwick<int> fw(m);
    int ans = 0;
    for (int i = 0, k = 0;i < n;++i) {
        while (k < vt.size() && vt[k][0] <= i) {
            fw.add(vt[k][1], vt[k][3]);
            fw.add(vt[k][2], -vt[k][3]);
            k++;
        }
        for (int j = 0;j < m;++j) {
            int res = x_sum[i] + y_sum[j];
            if (!map[i][j])res--;
            res -= fw.sum(j);
            ans = std::max(ans, res);
        }
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}