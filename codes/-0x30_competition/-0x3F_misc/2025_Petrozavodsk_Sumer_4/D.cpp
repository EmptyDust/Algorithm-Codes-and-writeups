#include <bits/stdc++.h>
#define fir first
#define sec second

using namespace std;

const int N = 9500;
const int inf32 = 0x3f3f3f3f;
using ll = long long;

using PII = pair<int, int>;

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<PII> edge(m + 1), query(q + 1);
    for (int i = 1; i <= m; i++) {
        cin >> edge[i].fir >> edge[i].sec;
        edge[i].fir++, edge[i].sec++;
        if (edge[i].fir > edge[i].sec)
            swap(edge[i].fir, edge[i].sec);
    }

    for (int i = 1;i <= q; i++) {
        cin >> query[i].fir >> query[i].sec;
    }

    auto check = [&] (int val) -> bool
    {
        auto getans = [&] (int idx) {
            if (idx <= val)
                return 1;
            return 0;
        };
        vector<PII> qu(q + 1);
        int lasu = 0, lasv = 0;
        // cout << val << endl;
        for (int i = 1; i <= q; i++) {
            lasu = lasu * 2 % n;
            lasv = lasv * 3 % n;
            if (i > 1) {
                lasu += getans(i - 1);
                lasv += getans(i - 1);
            }
            qu[i].fir = (lasu + query[i].fir) % n + 1;
            qu[i].sec = (lasv + query[i].sec) % n + 1;
            // cout << qu[i].fir << " " << qu[i].sec << endl;
            if (qu[i].fir > qu[i].sec)
                swap(qu[i].fir, qu[i].sec);
        }

        vector<int> f(n + 1, 0);
        iota(f.begin(), f.end(), 0);

        function<int(int)> find = [&] (int x) -> int
        {
            if (f[x] == x)
                return x;
            return f[x] = find(f[x]);
        };

        auto merge = [&] (int x, int y) -> bool
        {
            int fx = find(x);
            int fy = find(y);
            if (fx == fy)
                return false;
            f[fx] = fy;
            return true;
        };

        unordered_set<ll> s;
        
        for (int i = 1; i <= m; i++) {
            s.insert(1ll * edge[i].fir * 10000000 + edge[i].sec);
        }

        vector<int> iscut(q + 1, 0);
        // cout << "cut::  ";
        for (int i = 1; i <= q; i++) {
            ll rr = 1ll * qu[i].fir * 10000000 + qu[i].sec;
            if (s.find(rr) != s.end()) {
                s.erase(s.find(rr));
                iscut[i] = 1;
            }
            // cout << iscut[i] << " ";
        }
        // cout << endl;
        vector<int> ans(q + 1, 0);

        int lft = n;
        for (auto rr : s) {
            ll x = rr / 10000000;
            ll y = rr % 10000000;
            lft -= merge(x, y);
        }
        for (int i = q; i >= 1; i--) {
            ans[i] = (lft == 1);
            if (iscut[i])
                lft -= merge(qu[i].fir, qu[i].sec);
        }

        // cout << "ans::  ";
        // for (int i = 1; i <= q; i++) {
        //     cout << ans[i] << " ";
        // }
        // cout << endl;
        for (int i = 1; i <= q; i++) {
            int res = getans(i);
            if (ans[i] != res) {
                if (ans[i] == 1)
                    return true;
                else 
                    return false;
            }
        }
        return true;
    };

    int l = 0, r = q;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else 
            r = mid - 1;
    }

    for (int i = 1;i <= l; i++) {
        cout << "1\n";
    }
    for (int i = l + 1; i <= q; i++) {
        cout << "0\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
