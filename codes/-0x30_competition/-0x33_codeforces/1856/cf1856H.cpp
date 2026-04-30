#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1) return cout << a[0] << '\n', void();

    int ans = -1;
    vector<int> b;

    for (int k = 31; k >= 0; k--) {
        vector<array<int, 2>> val;
        for (int i = 0; i < n; i++) val.push_back({ a[i] >> k, a[i] });

        map<int, int> cot;
        for (auto& p : val) cot[p[0]]++;

        int limit = n / 2;
        bool jud = true;
        for (auto [u, v] : cot)
            if (v > limit) {
                jud = false;
                break;
            }

        if (!jud) continue;

        ans = k;
        int max = 0, maxi = -1;
        for (auto [u, c] : cot)if (max < c) {
            maxi = u;
            max = c;
        }
        sort(val.begin(), val.end());
        for (int i = 0, j = 0;j < n;++j) {
            std::swap(val[i], val[j]);
            if (val[i][0] == maxi)i++;
        }
        sort(val.begin() + max, val.end());
        // for (int& x : val)std::cout << x << ' ';std::cout << '\n';
        for (int i = 0;i < max;++i) {
            for (int j = i;j < n;j += max) {
                b.push_back(val[j][1]);
            }
        }
        break;
    }

    cout << ans << '\n';
    if (ans == -1)
        for (auto x : a) cout << x << " ";
    else
        for (auto x : b) cout << x << " ";

    cout << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
