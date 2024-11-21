#include <bits/stdc++.h>
using std::cin, std::cout, std::vector, std::array;
#define endl "\n"
#define ALL(x) x.begin(), x.end()
using PII = std::pair<int, int>;
using PIU = std::pair<int, unsigned>;
using T3I = std::tuple<int, int, int>;

template <typename T>
constexpr T power(T a, long long b) { T res = 1; for (;b;b >>= 1, a *= a) if (b & 1) res *= a; return res; }
template <int P>
class Mint {
public:
    int x;
    static int MOD;
    constexpr Mint() : x() {}
    constexpr Mint(long long _x) : x{ norm(_x % getMOD()) } {}

    constexpr static void setMOD(int _MOD) { MOD = _MOD; }
    constexpr static int getMOD() { return P > 0 ? P : MOD; }
    constexpr int norm(int x) const { return x >= 0 && x < getMOD() ? x : (x < 0 ? x += getMOD() : x -= getMOD()); }
    constexpr int val() const { return x; }
    explicit constexpr operator int() const { return x; }
    constexpr Mint operator-() const { Mint res; res.x = norm(getMOD() - x); return res; }
    constexpr Mint inv() const { assert(x != 0); return power(*this, getMOD() - 2); }
    constexpr Mint& operator*=(Mint rhs)& { x = 1LL * x * rhs.x % getMOD(); return *this; }
    constexpr Mint& operator+=(Mint rhs)& { x = norm(x + rhs.x); return *this; }
    constexpr Mint& operator-=(Mint rhs)& { x = norm(x - rhs.x); return *this; }
    constexpr Mint& operator/=(Mint rhs)& { return *this *= rhs.inv(); }
    friend constexpr Mint operator*(Mint lhs, Mint rhs) { Mint res = lhs; res *= rhs; return res; }
    friend constexpr Mint operator+(Mint lhs, Mint rhs) { Mint res = lhs; res += rhs; return res; }
    friend constexpr Mint operator-(Mint lhs, Mint rhs) { Mint res = lhs; res -= rhs; return res; }
    friend constexpr Mint operator/(Mint lhs, Mint rhs) { Mint res = lhs; res /= rhs; return res; }
    friend constexpr std::istream& operator>>(std::istream& is, Mint& a) { long long v; is >> v; a = Mint(v); return is; }
    friend constexpr std::ostream& operator<<(std::ostream& os, const Mint& a) { return os << a.val(); }
    friend constexpr bool operator==(Mint lhs, Mint rhs) { return lhs.val() == rhs.val(); }
    friend constexpr bool operator!=(Mint lhs, Mint rhs) { return lhs.val() != rhs.val(); }
};

template <>
int Mint<0>::MOD = 998'244'353;

template <int V, int P>
constexpr Mint<P> Cinv = Mint<P>(V).inv();

// 可以修改这里的P 如果需要将变量设为P,需要将P变为0
constexpr int P = 998'244'353;
using Z = Mint<P>;

using PUZ = std::pair<unsigned, Z>;

void solve()
{
    int n; cin >> n;
    vector<unsigned> aa(n + 1);
    vector<std::queue<int>> pos(31);
    for (int i = 1; i <= n; ++i) {
        cin >> aa[i];
        for (int j = 0; j < 31; ++j) if (aa[i] >> j & 1)
            pos[j].emplace(i);
    }

    vector<vector<PUZ>> toAdd(n + 1), toDel(n + 1);
    // vector<std::map<unsigned, Z>> dp(n+1);
    std::map<unsigned, Z> mp;
    toAdd[0].emplace_back(0, 1);
    toDel[1].emplace_back(0, 1);
    for (int i = 0; i <= n; ++i) {
        int L = i + 1, R = i + 1;
        vector<PIU> nxt;
        for (int j = 0; j < 31; ++j) {
            if (aa[i] >> j & 1) pos[j].pop();
            if (!pos[j].empty()) {
                nxt.emplace_back(1U << j, pos[j].front());
            }
        }
        std::ranges::sort(nxt,
            [&](const PIU& lhs, const PIU& rhs) {
                return lhs.second > rhs.second;
            }
        );

        unsigned OR = 0;
        while (!nxt.empty() && (OR == 0 || OR < aa[i])) {
            auto [v, p] = nxt.back(); nxt.pop_back();
            while (!nxt.empty() && nxt.back().second == p) {
                v |= nxt.back().first; nxt.pop_back();
            }
            OR |= v;
            R = p;
        }

        for (auto& [val, cnt] : toDel[i]) {
            auto it = mp.find(val);
            if (it->second == cnt) mp.erase(it);
            else it->second -= cnt;
        }
        for (auto& [val, cnt] : toAdd[i]) mp[val] += cnt;
        if (i == n) break;

        for (auto [val, cnt] : mp) {
            int top = int(nxt.size()) - 1;
            int curL = L, curR = R;
            unsigned curSum = OR;
            while (top >= 0 && curSum < val) {
                auto [v, p] = nxt[top--];
                while (top >= 0 && nxt[top].second == p)
                    v |= nxt[top--].first;
                curSum |= v; curR = p;
            }
            if (curSum < val) continue;

            toAdd[curR].emplace_back(curSum, cnt);
            while (top >= 0) {
                curL = curR;
                auto [v, p] = nxt[top--];
                curR = p;
                toDel[curR].emplace_back(curSum, cnt);
                curSum |= v;
                toAdd[curR].emplace_back(curSum, cnt);
            }
        }
    }

    Z res = 0;
    for (auto [_, cnt] : mp) res += cnt;
    cout << res << endl;
}

int32_t main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    std::ifstream in("C++/in.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    int T = 1;
    // std::cin >> T;
    while (T--) solve();
    return 0;
}