#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::vector<int> a, b, c;
    int n, m, l, num;
    std::cin >> n;
    for (int i = 0;i < n;++i)std::cin >> num, a.push_back(num);
    std::cin >> m;
    for (int i = 0;i < m;++i)std::cin >> num, b.push_back(num);
    std::cin >> l;
    for (int i = 0;i < l;++i)std::cin >> num, c.push_back(num);
    std::set<int> st;
    for (int i = 0;i < n;++i)for (int j = 0;j < m;++j)for (int k = 0;k < l;++k)
        st.insert(a[i] + b[j] + c[k]);
    int q;std::cin >> q;
    for (int i = 0;i < q;++i) {
        std::cin >> num;
        std::cout << (st.count(num) ? "Yes" : "No") << '\n';
    }
    return 0;
}