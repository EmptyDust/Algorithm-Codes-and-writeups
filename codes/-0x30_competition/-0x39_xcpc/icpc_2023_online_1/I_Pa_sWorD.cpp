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

int n;
std::string s;

i64 cnt_l[26], cnt_u[26], cnt_d[10];
i64 n_cnt_l[26], n_cnt_u[26], n_cnt_d[10];

bool l, u, d;
void add(char ch, i64 a) {
    if (d && isdigit(ch)) {
        n_cnt_d[ch - '0'] = (n_cnt_d[ch - '0'] + a) % mod;
    }
    if (u && isupper(ch)) {
        n_cnt_u[ch - 'A'] = (n_cnt_u[ch - 'A'] + a) % mod;
    }
    if (l && islower(ch)) {
        n_cnt_l[ch - 'a'] = (n_cnt_l[ch - 'a'] + a) % mod;
    }
}

void clear() {
    for (int i = 0;i < 26;++i) {
        n_cnt_l[i] = 0;
        cnt_l[i] = 0;
    }
    for (int i = 0;i < 26;++i) {
        n_cnt_u[i] = 0;
        cnt_u[i] = 0;
    }
    for (int i = 0;i < 10;++i) {
        n_cnt_d[i] = 0;
        cnt_d[i] = 0;
    }
}

void merge() {
    for (int i = 0;i < 26;++i) {
        cnt_l[i] = n_cnt_l[i];
        n_cnt_l[i] = 0;
    }
    for (int i = 0;i < 26;++i) {
        cnt_u[i] = n_cnt_u[i];
        n_cnt_u[i] = 0;
    }
    for (int i = 0;i < 10;++i) {
        cnt_d[i] = n_cnt_d[i];
        n_cnt_d[i] = 0;
    }
}

i64 get_sum() {
    i64 sum = 0;
    for (int i = 0;i < 26;++i) {
        sum = (sum + cnt_l[i]) % mod;
    }
    for (int i = 0;i < 26;++i) {
        sum = (sum + cnt_u[i]) % mod;
    }
    for (int i = 0;i < 10;++i) {
        sum = (sum + cnt_d[i]) % mod;
    }
    return sum;
}

i64 cal() {
    {
        char ch = s[0];
        if (ch == '?') {
            for (int i = 0;i < 26;++i) {
                add('a' + i, 1);
            }
            for (int i = 0;i < 26;++i) {
                add('A' + i, 1);
            }
            for (int i = 0;i < 10;++i) {
                add('0' + i, 1);
            }
        }
        if (islower(ch)) {
            add(ch, 1);
            ch -= 'a' - 'A';
        }
        if (isdigit(ch) || isupper(ch)) {
            add(ch, 1);
        }
        merge();
    }

    for (int i = 1;i < n;++i) {
        char ch = s[i];
        i64 sum = get_sum();
        if (ch == '?') {
            // std::cout << "sum:" << sum << ' ';
            // std::cout << cnt_u[0] << '\n';
            for (int i = 0;i < 26;++i) {
                add('a' + i, sum - cnt_l[i]);
            }
            // std::cout << n_cnt_u[0] << ' ';
            for (int i = 0;i < 26;++i) {
                add('A' + i, sum - cnt_u[i]);
                // std::cout << sum - cnt_u[i] << ' ';
                // if (n_cnt_u[0])std::cout << i << " ";
                // std::cout << n_cnt_u[0] << ' ';
            }
            for (int i = 0;i < 10;++i) {
                add('0' + i, sum - cnt_d[i]);
            }
        }
        if (islower(ch)) {
            add(ch, sum - cnt_l[ch - 'a']);
            ch -= 'a' - 'A';
        }
        if (isupper(ch)) {
            add(ch, sum - cnt_u[ch - 'A']);
        }
        if (isdigit(ch)) {
            add(ch, sum - cnt_d[ch - '0']);
        }
        merge();
    }
    // std::cout << get_sum() << '\n';
    // i64 sum = 0;
    // for (int i = 0;i < 26;++i) {
    //     sum = (sum + cnt_l[i]) % mod;
    // }
    // for (int i = 0;i < 26;++i) {
    //     sum = (sum + cnt_u[i]) % mod;
    // }
    // for (int i = 0;i < 10;++i) {
    //     sum = (sum + cnt_d[i]) % mod;
    // }
    return get_sum();
}

void solve() {
    std::cin >> n;
    std::cin >> s;
    i64 ans = 0;
    // l = 0, u = 1, d = 1;
    // cal();
    for (int m = 0;m < (1 << 3);++m) {
        int cnt = 0;
        l = u = d = 0;
        for (int i = 0;i < 3;++i) {
            if (m >> i & 1) {
                cnt++;
                if (i == 0)l = 1;
                if (i == 1)u = 1;
                if (i == 2)d = 1;
            }
        }
        ans = (ans + (cnt % 2 ? 1 : -1) * cal() % mod) % mod;
        clear();
    }
    std::cout << (ans + mod) % mod;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
        std::cout << '\n';
    }
    return 0;
}