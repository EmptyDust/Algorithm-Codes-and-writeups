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
    struct node
    {
        T data = 0;
        node* next = nullptr;
        node() {}
        node(T d, node* n) :data(d), next(n) {}
    }root;
    int len = 0;
public:
    void clear() { root.next = nullptr;len = 0; }
    bool isEmpty() { return root.next == nullptr; }
    int length() { return len; }
    T peek() {
        if (isEmpty())return T();
        return root.next->data;
    }
    T pop() {
        if (isEmpty())return T();
        node r = *root.next;
        root.next = r.next;
        len--;
        return r.data;
    }
    void push(T x) {
        root.next = new node(x, root.next);
        len++;
    }
    void display() {
        auto x = root.next;
        while (x) {
            std::cout << x->data << " ";
            x = x->next;
        }
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