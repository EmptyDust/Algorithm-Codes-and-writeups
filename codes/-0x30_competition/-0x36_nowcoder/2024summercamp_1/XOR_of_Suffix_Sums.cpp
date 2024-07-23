#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 1e6, MAXN = 1e6 + 10, inf = 1e9, mod = 2097152, S = 21;
using pii = std::pair<i64, i64>;

template<typename T>
struct Fenwick {
    int n;
    std::vector<T> a;

    Fenwick(int n_ = 0) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        a.assign(n + 5, T{});
    }

    void add(int x, const T& v) {
        x++;
        for (int i = x; i <= n; i += i & -i) {
            a[i] = a[i] + v;
        }
    }

    T sum(int x) {
        x++;
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i];
        }
        return ans;
    }

    T rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    int select(const T& k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i] <= k) {
                x += i;
                cur = cur + a[x];
            }
        }
        return x;
    }
};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int q;std::cin >> q;
    std::vector<pii> ps(q);
    for (auto& [t, v] : ps)std::cin >> t >> v;
    i64 sum = 0;
    std::vector<Fenwick<int>> fw(S, Fenwick<int>(mod));
    std::vector<i64> pre;
    std::vector<int> nums;
    for (int s = 0;s < S;++s)fw[s].add(0, 1);
    for (auto [t, v] : ps) {
        while (t--) {
            sum -= nums.back();
            nums.pop_back();

            int mask = 0;
            for (int s = 0;s < S;++s) {
                mask |= (pre.back() >> s & 1) << s;
                fw[s].add(mask, -1);
            }
            pre.pop_back();
        }
        sum += v;
        nums.push_back(v);

        if (pre.size())v += pre.back();
        pre.push_back(v);
        int mask = 0;
        for (int s = 0;s < S;++s) {
            mask |= (pre.back() >> s & 1) << s;
            fw[s].add(mask, 1);
        }

        mask = 0;
        int ans = 0;
        for (int s = 0;s < S;++s) {
            mask |= (sum >> s & 1) << s;
            int mask2 = mask - (1 << s);
            if (mask2 >= 0) {
                int sum = fw[s].rangeSum(0, mask2) + fw[s].rangeSum(mask + 1, 1 << s + 1);
                ans |= (sum % 2) << s;
            }
            else {
                mask2 += 1 << s + 1;
                int sum = fw[s].rangeSum(mask + 1, mask2);
                ans |= (sum % 2) << s;
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}