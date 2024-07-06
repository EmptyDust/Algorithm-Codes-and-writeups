#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 1e6 + 10;
using i64 = long long;
using pii = pair<int, int>;
int a[MAXN], c[MAXN];
i64 pre[MAXN];

i64 cal(pii x) {
    auto [l, r] = x;
    if (l > r) return 0;
    r++;
    i64 cnt = 1ll * (r - l + 1) * (r - l + 1 + 1) / 2 - (r - l + 1);
    return cnt;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) c[i] = a[i + 1] - a[i];

    if (n == 1) {
        while (q--)
            cout << 1 << endl;
        return 0;
    }

    vector<pii> quj;
    int dsz = n;
    for (int i = 1;i < dsz;) {
        int st = i;//end
        while (i < dsz && c[st] == c[i])
            i++;
        quj.push_back({ st, i - 1 });
    }

    pre[0] = cal(quj[0]);
    for (int i = 1; i < quj.size(); ++i)
        pre[i] = pre[i - 1] + cal(quj[i]);

    while (q--) {
        int l, r;cin >> l >> r;
        i64 ans = r - l + 1;r--;

        auto it2 = lower_bound(quj.begin(), quj.end(), pii{ r + 1, 0 });
        auto it = lower_bound(quj.begin(), quj.end(), pii{ l, 0 });

        if (it == it2) {
            ans += cal({ l,r });
        }
        else {
            it2--;
            auto itf = it->first;
            auto it2f = it2->first;
            ans += cal({ l, itf - 1 });
            ans += cal({ it2f, r });

            if (it2 != quj.begin()) {
                it2--;
                auto back = it2 - quj.begin();
                ans += pre[back];

                if (it != quj.begin()) {
                    auto front = it - quj.begin() - 1;
                    ans -= pre[front];
                }
            }
        }

        cout << ans << endl;
    }
}