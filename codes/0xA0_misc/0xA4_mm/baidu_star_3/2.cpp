#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
using pii = pair<int, int>;

void solve() {
    int n;cin >> n;
    vector<pii> pts;
    int pre = 0;
    for (int i = 0;i < n;++i) {
        int x;cin >> x;
        char c;cin >> c;
        if (c == 'L') {
            pts.push_back({ pre - x + 1, pre });
            pre -= x - 1;
        }
        else {
            pts.push_back({ pre,pre + x - 1 });
            pre += x - 1;
        }
    }
    map<int, int> mp;
    for (auto [l, r] : pts) {
        mp[l]++;
        mp[r + 1]--;
    }

    ll ans = 0;
    ll curx = -inf, cur = 0;
    for (auto [x, cnt] : mp) {
        //std::cout << curx << ' ' << x << ' ' << cur << ' ' << (x - curx) * cur << '\n';
        if (cur % 4 == 1)
            ans += x - curx;
        cur += cnt;
        curx = x;
    }
    cout << ans;
    // -5 -4 -3 -2 -1 0 1 2 3 4 5 6 7 8 9 10
    // 2  2  2  4   4 5 3 2 2 2
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }
}