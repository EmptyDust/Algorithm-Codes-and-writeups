#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 998244353;
using pii = std::pair<int, int>;

#define int long long

struct Mi64 {
    i64 value;
    Mi64() {}
    Mi64(i64 value) { this->value = value; }
    Mi64 operator * (const i64 w) {
        return value * w % mod;
    }
    Mi64 operator * (const Mi64 w) {
        return value * w.value % mod;
    }
    Mi64 operator + (const Mi64 w) {
        return (value + w.value) % mod;
    }
    Mi64 operator - (const Mi64 w) {
        return((value - w.value) % mod + mod) % mod;
    }
    bool operator == (const Mi64 w) {
        return value == w.value;
    }
};

i64 qpow(i64 x, i64 p) {
    i64 ret = 1;
    while (p) {
        if (p & 1)ret = ret * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return ret;
}

#define inv(x) qpow(x,mod-2)

Mi64 comb2[(int)1e7 + 10];
void init() {
    comb2[2] = comb2[1] = 1;
    for (int i = 3;i <= (int)1e7;++i) {
        comb2[i] = comb2[i - 1] + i - 1;
        // std::cout << comb2[i] << ' ';
    }
    for (int i = 4;i <= (int)1e7;i++) {
        comb2[i] = comb2[i - 2] * comb2[i];
    }
}

void solve() {
    int n;std::cin >> n;
    //(1 - p) / 2 + p
    //p:sum(h) % 2 == 1 and sum(h % 2) == 1 
    //(sum(h) - 1) / 2 次选择全部相同
    //(sum(h) - 1) / 2) / (sum(h))
    std::vector<int> hs;
    int cnt = 0;
    int sum = 0;
    for (int i = 0;i < n;++i) {
        char c;int h;std::cin >> c >> h;
        sum += h;
        if (h % 2) {
            cnt++;
        }
        hs.push_back(h);
    }
    if (cnt == 0) {
        Mi64 p = 1;
        for (int x : hs)if (x > 1) {
            p = p * comb2[x];
        }
        p = p * inv(comb2[sum].value);
        auto ans = (p * -1 + 1) * 499122177;
        ans = ans - 0;
        std::cout << ans.value;
    }
    else if (cnt == 1) {
        Mi64 p = 1;
        for (int x : hs)if (x > 1) {
            p = p * comb2[x];
        }
        p = p * inv(comb2[sum].value);
        auto ans = p + (p * -1 + 1) * 499122177;
        ans = ans - 0;
        std::cout << ans.value;
    }
    else std::cout << 499122177;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    init();
    int t;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}