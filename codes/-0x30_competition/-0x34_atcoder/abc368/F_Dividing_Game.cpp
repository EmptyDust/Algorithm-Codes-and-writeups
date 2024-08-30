#include <bits/stdc++.h>

#define ranges std::ranges
#define views std::views

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using pii = std::pair<int, int>;
using a3 = std::array<int, 3>;
using a4 = std::array<int, 4>;

const int N = 1e6;
const int MAXN = 1e6 + 10;
const int inf = 1e9;
// const int mod = 1e9 + 7;
const int mod = 998244353;

std::vector<int> primes;
int p[MAXN];
void init() {
    for (int i = 2;i <= N;++i)if (!p[i]) {
        primes.push_back(i);
        p[i] = i;
        for (i64 j = 1ll * i * i;j <= N;j += i) {
            p[j] = i;
        }
    }
}

void solve() {
    int n;std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a) {
        int y;
        std::cin >> y;
        while (y != 1) {
            y /= p[y];
            x++;
        }
    }
    int ans = 0;
    for (int x : a) {
        ans ^= x;
    }
    std::cout << (ans ? "Anna" : "Bruno ");
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    init();
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}