#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN = 1e6 + 10;
using pt = pair<int, int>;

void solve() {
    int n, l;cin >> n >> l;
    vector<pt> pts(n);
    for (int i = 0;i < n;++i)cin >> pts[i].first >> pts[i].second;
    sort(pts.begin(), pts.end(), [&](auto a, auto b) {return a.second < b.second;});
    int ans = 0;
    for (int i = 0;i < n;++i) {
        int st = pts[i].second;
        priority_queue<int> pq;
        int sum = pts[i].first;
        if (sum > l)continue;
        else ans = max(ans, (int)1);
        for (int j = i + 1;j < n;++j) {
            int cost = pts[j].second - st;
            sum += pts[j].first;
            pq.push(pts[j].first);
            while (!pq.empty() && sum + cost > l) {
                sum -= pq.top();
                pq.pop();
            }
            if (sum + cost <= l)ans = max(ans, (int)pq.size() + 1);
        }
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    int t;cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
    return 0;
}