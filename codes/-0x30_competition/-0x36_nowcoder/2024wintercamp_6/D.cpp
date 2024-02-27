#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 1e6 + 10, mod = 1e9 + 7;
int nums[MAXN];
vector<int> adj[MAXN];

signed main() {
    ios::sync_with_stdio(false);
    vector<int> fb = { 0,1 };
    while (fb[fb.size() - 1] < 1e9) {
        fb.push_back(fb[fb.size() - 1] + fb[fb.size() - 2]);
    }
    unordered_map<int, array<int, 3>> mp;
    for (int a : fb)for (int b : fb)for (int c : fb) {
        if (!mp.count(a + b + c)) {
            mp[a + b + c] = { a,b,c };
        }
    }
    int q, n;cin >> q;
    while (q--) {
        cin >> n;
        if (mp.count(n)) {
            cout << mp[n][0] << ' ' << mp[n][1] << ' ' << mp[n][2] << '\n';
        }
        else
            cout << -1 << '\n';
    }
    return 0;
}