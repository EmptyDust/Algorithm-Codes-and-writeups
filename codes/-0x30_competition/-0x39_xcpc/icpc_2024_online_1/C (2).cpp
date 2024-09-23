#include<bits/stdc++.h>

using u64 = unsigned long long;
using pii = std::pair<int, int>;
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n; std::cin >> n;
    std::vector<u64> a(n + 2);
    std::vector<pii> p(n);
    std::vector<int> cntl(n + 2), cntr(n + 2);
    std::set<pii> st2;bool f = false;
    for (int i = 0;i < n;++i) {
        int& l = p[i].first;
        int& r = p[i].second;
        std::cin >> l >> r;
        if (st2.count(p[i]))f = true;
        else st2.insert(p[i]);
        cntl[l]++;
        cntr[r]++;
    }
    if (f) {
        std::cout << 0;
        return;
    }
    std::sort(p.begin(), p.end(), [&](pii a, pii b) {return a.second < b.second;});
    std::vector<pii> cur;
    for (int i = 1, l = 1, j = 0;i <= n;++i) {
        while (j < n && p[j].second <= i) {
            cur.push_back(p[j]);
            j++;
        }
        cntl[i] += cntl[i - 1];
        cntr[i] += cntr[i - 1];
        if (cntr[i] > i || cntl[i] < i) {
            std::cout << 0;
            return;
        }
        if (cntr[i] == i) {
            for (int t = 0;t < cur.size();++t) {
                int& ll = cur[t].first;
                int& rr = cur[t].second;
                rr = std::min(rr, i);
                ll = std::max(ll, l);
            }
            cur.clear();
            l = i + 1;
        }
    }
    // for (int i = 1, l = 1, j = 0;i <= n;++i) {
    //     while (j < n && p[j].second <= i) {
    //         p[j].first = std::max(l, p[j].first);
    //         j++;
    //     }
    //     if (cntr[i] == i) {
    //         l = i + 1;
    //     }
    // }
    // for (int i = 1;i <= n;++i)cntl[i] = 0;
    // for (int i = 0;i < n;++i)cntl[p[i].first]++;
    // for (int i = n;i >= 1;--i)cntl[i] += cntl[i - 1];
    // std::sort(p.begin(), p.end(), [&](pii a, pii b) {return a.first > b.first;});
    // for (int i = n, r = n, j = 0;i >= 1;--i) {
    //     while (j < n && p[j].first >= i) {
    //         p[j].first = std::min(r, p[j].second);
    //         j++;
    //     }
    //     if (cntl[i] == n + 1 - i) {
    //         r = i - 1;
    //     }
    // }
    for (int i = 0;i < n;++i) {
        int& l = p[i].first;
        int& r = p[i].second;
        //        std::cout << l << ' ' << r << '\n';
        u64 rd = rng();
        a[l] ^= rd;
        a[r + 1] ^= rd;
    }

    std::set<u64> st;
    for (int i = 1;i <= n;++i) {
        a[i] ^= a[i - 1];
        if (st.count(a[i])) {
            std::cout << 0;
            return;
        }
        st.insert(a[i]);
    }
    std::cout << 1;
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
