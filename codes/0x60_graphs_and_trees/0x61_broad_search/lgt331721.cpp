#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
using pt = std::pair<int, int>;
std::vector<pt> adj[MAXN];

struct cmp {
    bool operator()(pt a, pt b) {
        return a.second > b.second;
    }
};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> nums(n, 0);
    for (int i = 0;i < n;++i)std::cin >> nums[i];
    int x, y, w1, w2;
    for (int i = 0;i < m;++i) {
        std::cin >> x >> y >> w1 >> w2;
        x--, y--;
        adj[x].push_back({ y,w1 + w2 });
        adj[y].push_back({ x,w2 + w1 });
    }
    std::vector<int> zbs(n), f(nums);
    std::iota(zbs.begin(), zbs.end(), 0);
    std::sort(zbs.begin(), zbs.end(), [&](int a, int b) {return nums[a] < nums[b];});
    i64 ans = 0;
    for (int i = 0;i < n;++i)if (f[zbs[i]] == nums[zbs[i]]) {
        ans += nums[zbs[i]];
        std::priority_queue<pt, std::vector<pt>, cmp> pq;
        pq.push({ zbs[i],0 });
        std::vector<bool> visited(n, false);
        while (!pq.empty()) {
            pt cur = pq.top();
            pq.pop();
            if (visited[cur.first])continue;
            f[cur.first] = std::min(f[cur.first], cur.second);
            visited[cur.first] = true;
            for (auto [nxt, w] : adj[cur.first]) {
                if (!visited[nxt] && w < f[nxt]) {
                    pq.push({ nxt,w });
                }
            }
        }
    }
    ans += std::accumulate(f.begin(), f.end(), (i64)0);
    std::cout << ans;
    return 0;
}