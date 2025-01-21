#include<bits/stdc++.h>

using namespace std;
#define int long long
#define ll long long
#define double long double
#define all(x) (x).begin(), (x).end()
#define nall(x) next((x).begin()), (x).end()
constexpr int mod = 998244353;
constexpr int M = 5e5 + 3;
constexpr int N = 2e6 + 3;
constexpr int B = 500 + 3;
constexpr double eps = 1e-7;
constexpr int H = 13331;


constexpr int iow = (1ll << 16) - 16;
constexpr int tov = 1ll << 6;
constexpr int bitter = ((1ll << 6) - 4) << 4;

vector<int> ans(1ll << 12);

void modify(int p, int a, int b, int c) {
    ans[p] = a, ans[p + 1] = b, ans[p + 2] = c;
}

void slove() {
    int x; cin >> x;
    modify(0, 0, 0, 0x0100);
    for (int i = 0; i < 16; ++i) {
        int v = (x >> i) & 1;
        int to = 0x0100 + i + i + i;
        if (v) modify(i + i + i + 3, 0, 0xfff0, 0x0fff);
        else  modify((to + 3) | tov, 0, 0xfff0, 0x0fff);
        modify(to, i | 0xfff0, (to << 4) + (v ? 0x28 : 0x26), to + 3);
    }
    // 0xfff0 0b1111111111111111
    modify(0x0100 + 0x0010 * 3, 0x28, 0xfff0, 0x0fff);
    cout << setfill('0') << hex;
    for (int i = 0; i < (1 << 12) - 1; i++)
        cout << setw(4) << ans[i] << ' ';
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--)
        slove();
    return 0;
}