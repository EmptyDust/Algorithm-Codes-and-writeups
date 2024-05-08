#include <bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int MAXN = 100;
int n, m, t[MAXN];

int j(int x) {
    if (x == 1)return 1;
    return x * j(x - 1);
}

signed main() {
    ios::sync_with_stdio(false);
    int n, m, k;cin >> n >> m >> k;
    if (n == 2) {
        cout << 1 << '\n';
        if (m == 1 && k == 2)cout << "aye AYE";
        if (m == 2 && k == 1)cout << "AYE aye";
        return 0;
    }
    m--, k--;
    vector<string> ss(n - 2);
    for (int i = 0;i < n - 2;++i) {
        cin >> ss[i];
        if (ss[i] == "aye" || ss[i] == "AYE")
            --i;
    }
    sort(ss.begin(), ss.end());
    vector<string> tmp(ss);
    cout << j(n - 2) << '\n';
    do {
        int ff = 0;
        for (int i = 0;i < n;++i) {
            if (i == m) { cout << "aye";if (i != n - 1)cout << ' ';ff++;continue; }
            if (i == k) { cout << "AYE";if (i != n - 1)cout << ' ';ff++;continue; }
            cout << ss[i - ff];if (i != n - 1)cout << ' ';
        }
        cout << '\n';
        next_permutation(ss.begin(), ss.end());
    } while (ss != tmp);
    return 0;
}