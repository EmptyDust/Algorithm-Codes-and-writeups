#include <bits/stdc++.h>
using namespace std;

string s;
int d[3][205][205];

int F(int t, int l, int r) {
    if (l > r) return 0;
    if (~d[t][l][r]) return d[t][l][r];
    int& res = d[t][l][r];
    res = 0;
    if (t == 0) {
        if (s[l] == '{' && s[r] == '}')
            res = (l + 1 == r) || F(2, l + 1, r - 1);
    }
    else if (t == 1) {
        res = (l == r) || F(0, l, r);
    }
    else {
        if (F(1, l, r)) res = 1;
        else {
            for (int i = l; i < r; ++i) {
                if (s[i] == ',' && F(1, l, i - 1) && F(2, i + 1, r)) {
                    res = 1; break;
                }
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    if (cin >> s) {
        memset(d, -1, sizeof(d));
        cout << (F(0, 0, s.size() - 1) ? "Set" : "No Set");
    }
    return 0;
}