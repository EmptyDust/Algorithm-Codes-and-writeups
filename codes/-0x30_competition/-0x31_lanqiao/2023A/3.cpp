#include <bits/stdc++.h>
using i64 = long long;
constexpr int MAXN = 1e6 + 10;
int nums[MAXN], n;
using pt = std::pair<int, int>;

struct BigInt {
    std::vector<int> num;
    bool flag = true;
    BigInt(std::vector<int> num, bool flag = true) {
        this->num = num;
        this->flag = flag;
    }
    BigInt(std::string s) {
        std::reverse(s.begin(), s.end());
        for (char ch : s) {
            if (ch == '-') {
                continue;
            }
            num.push_back(ch - '0');
        }
    }
    BigInt operator-(BigInt x) {
        auto a = this->num, b = x.num;
        bool f = true;
        if (a.size() < b.size())std::swap(a, b), f = false;
        if (a.size() == b.size()) {
            while (a.back() == b.back()) {
                a.pop_back();
                b.pop_back();
            }
            if (a.back() < b.back())swap(a, b), f = false;
        }
        bool m = 0;
        for (int i = 0;i < b.size();++i) {
            a[i] -= b[i] + m;
            m = false;
            if (a[i] < 0) {
                m = true;
                a[i] += 10;
            }
        }
        int i = b.size();
        while (m) {
            a[i]--;
            m = false;
            if (a[i] < 0) {
                m = true;
                a[i] += 10;
            }
            i++;
        }
        return BigInt(a, f);
    }
    BigInt operator*(BigInt x) {
        auto a = this->num, b = x.num;
        std::vector<int> ans(a.size() + b.size());
        for (int i = 0;i < a.size();++i)
            for (int j = 0;j < b.size();++j) {
                int pos = i + j;
                ans[pos] += a[i] * b[j];
            }
        int z = 0;
        for (int& num : ans) {
            num += z;
            z = num / 10;
            num %= 10;
        }
        while (ans.back() == 0)ans.pop_back();
        return BigInt(ans);
    }
    void print() {
        if (!flag)std::cout << '-';
        while (num.back() == 0)num.pop_back();
        std::reverse(num.begin(), num.end());
        for (int x : num)std::cout << x;
    }
};

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    std::string a, b;std::cin >> a >> b;
    if (a == b) {
        std::cout << 0;
        return 0;
    }
    BigInt ai = (*new BigInt(a));
    BigInt bi = (*new BigInt(b));
    BigInt ans = ai * ai - bi * bi;
    ans.print();
    return 0;
}