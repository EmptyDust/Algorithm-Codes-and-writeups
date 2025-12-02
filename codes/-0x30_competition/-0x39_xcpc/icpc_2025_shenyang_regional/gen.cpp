#include<bits/stdc++.h>
#define int long long
#define fir first
#define sec second
using namespace std;
typedef long long ll;
using a2 = std::array<int, 2>;

using PII = pair<int, int>;

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void __() {
    std::cout << 1 << '\n';
    int n = rng() % 300 + 1;
    std::vector adj(n + 1, std::vector<int>(n + 1));
    std::vector<int> vis(n + 1);
    int m = 0;
    std::vector<a2> edges;
    for (int i = 2;i <= n;++i) {
        int x = rng() % (i - 1) + 1;
        adj[i][x] = 1;
        for (int j = 1;j < i;++j) {
            if (!adj[i][j])adj[i][j] = rng() % 2;
            m += adj[i][j];
        }
    }
    int a = rng() % n + 1, b = rng() % n + 1;
    if (a == b) b = (b + 1) % n + 1;
    std::cout << n << ' ' << m << ' ' << a << " " << b << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin>>_;
    while (_--) {
        __();
    }
}