#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n;

bool check(vector<vector<char>>& cmp, vector<vector<char>>& target) {
    for (int i = 0;i < n;++i)
        for (int j = 0;j < n;++j)
            if (cmp[i][j] != target[i][j])
                return false;
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> n;
    vector<vector<char>> mp(n, vector<char>(n));
    vector<vector<char>> target(n, vector<char>(n));
    for (int i = 0;i < n;++i)
        for (int j = 0;j < n;++j)
            cin >> mp[i][j];
    for (int i = 0;i < n;++i)
        for (int j = 0;j < n;++j)
            cin >> target[i][j];

    bool f = false;
    for (int t = 0;t < 4;++t) {
        vector<vector<char>> tmp(mp), f1(mp), f2(mp);

        if (check(tmp, target)) {
            f = true;
            break;
        }

        for (int i = 0;i < n;++i) {
            for (int j = 0;j < n;++j) {
                f1[i][j] = tmp[n - 1 - i][j];
                f2[i][j] = tmp[i][n - 1 - j];
            }
        }

        if (check(f1, target) || check(f2, target)) {
            f = true;
            break;
        }

        for (int i = 0;i < n;++i)
            for (int j = 0;j < n;++j)
                tmp[i][j] = mp[j][n - 1 - i];

        mp = tmp;
    }
    cout << (f ? "Yes" : "No");
    return 0;
}