#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10, inf = 1e9, mod = 1e9 + 7;
int nums[MAXN], n, k;
using pt = std::pair<int, int>;

#define lowbit(x) x&-x
i64 BIT[MAXN];
void update(int pos, int num = 1) {
    for (int i = pos;i <= 1e6;i += lowbit(i))
        BIT[i] += num;
}
i64 query(int pos) {
    i64 ret = 0;
    for (int i = pos;i;i -= lowbit(i))
        ret += BIT[i];
    return ret;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> k;
    std::set<int> st;
    std::vector<std::string> ss(n + 1);
    for (int i = 1;i <= n;++i)std::cin >> ss[i];
    st.insert(0);
    for (int i = 1, j = 0;i <= n;++i) {
        std::string& s = ss[i];
        if (s == "byl")j++;
        else j -= k;
        st.insert(j);
    }
    i64 ans = 0;
    std::map<int, int> mp;int xi = 2;
    for (int x : st)mp[x] = xi++;
    update(mp[0]);
    for (int i = 1, j = 0;i <= n;++i) {
        std::string& s = ss[i];
        if (s == "byl")j++;
        else j -= k;
        ans += query(mp[j] - 1);
        update(mp[j]);
    }
    std::cout << ans;
    return 0;
}