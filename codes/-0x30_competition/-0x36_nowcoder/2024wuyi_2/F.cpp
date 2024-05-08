#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 2e6 + 10, MAXN = 2e6 + 100, inf = 1e9, mod = 1e9 + 7;
int n, m;
std::vector<int> axis[MAXN], adj[MAXN];
std::set<int> to_be_erase[MAXN];
using pt = std::pair<int, int>;

void solve() {
    std::cin >> n >> m;
    int k;
    std::vector<int> nums;
    for (int i = 1;i <= n;++i) {
        std::cin >> k;
        int num;
        for (int j = 1;j <= k;++j) {
            std::cin >> num;
            adj[i].push_back(num);
            nums.push_back(num);
        }
    }
    int ki = 1;
    std::sort(nums.begin(), nums.end());
    std::map<int, int> ls, ls_re;
    for (int& x : nums)if (!ls.count(x)) {
        ls_re[ki] = x;
        ls[x] = ki++;
    }
    for (int i = 1;i <= n;++i)for (int& x : adj[i]) {
        axis[ls[x]].push_back(i);
    }
    std::set<int> st;
    std::map<int, int> last_x;
    int ans = 1e9;
    for (int i = 1, j = 1;i <= N;++i)if (axis[i].size()) {
        for (int& x : axis[i]) {
            st.insert(x);
            to_be_erase[i].insert(x);
            if (last_x.count(x))
                to_be_erase[last_x[x]].erase(x);
            last_x[x] = i;
        }
        while (st.size() >= m && j <= i) {
            ans = std::min(ans, ls_re[i] - ls_re[j]);
            for (int x : to_be_erase[j]) {
                st.erase(x);
                last_x.erase(x);
            }
            to_be_erase[j].clear();
            j++;
        }
    }
    std::cout << ans;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    solve();
    return 0;
}