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

template<class T>
class myStack {
    std::vector<int> data;
public:
    void clear() { data.clear(); }
    bool isEmpty() { return data.empty(); }
    int length() { return data.size(); }
    T peek() {
        if (isEmpty())return T();
        return data.back();
    }
    T pop() {
        if (isEmpty())return T();
        T r = data.back();
        data.pop_back();
        return r;
    }
    void push(T a) {
        data.push_back(a);
    }
    void display() {
        for (T x : data)
            std::cout << x << ' ';
    }
};

void solve() {
    myStack<int> stack;
    std::cout << stack.isEmpty() << '\n';
    stack.push(1);
    std::cout << stack.length() << '\n';
    stack.push(2);
    stack.display();
    std::cout << '\n';
    std::cout << stack.peek() << '\n';
    stack.pop();
    std::cout << stack.pop() << '\n';
    stack.push(3);
    std::cout << stack.length() << '\n';
    stack.clear();
    std::cout << stack.length() << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}