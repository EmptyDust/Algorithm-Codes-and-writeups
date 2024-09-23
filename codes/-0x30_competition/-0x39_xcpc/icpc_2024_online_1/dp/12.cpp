#include<bits/stdc++.h>

using u64 = unsigned long long;
using pii = std::pair<int, int>;
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; std::cin >> n;
    std::vector<pii> p(n);
    std::vector<int> a(n);
    for (int i = 0;i < n;++i) {
        int& l = p[i].first;
        int& r = p[i].second;
        std::cin >> l >> r;
        u64 rd = rng();
    }
    std::iota(a.begin(), a.end(), 1);
    int cnt = 0;
    do {
        bool ok = 1;
        for (int i = 0;i < n;++i) {
            if (p[i].first <= a[i] && a[i] <= p[i].second) {

            }
            else {
                ok = false;
                break;
            }
        }
        if(ok){
//        	for(int x:a)std::cout<<x<<" ";
//        	std::cout<<std::endl;
		}
        cnt += ok;
    } while (std::next_permutation(a.begin(), a.end()));
    std::cout << cnt % 2;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;std::cin >> t;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}
