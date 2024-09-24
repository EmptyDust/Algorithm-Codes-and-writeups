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
class List {
private:
    struct Info {
        T data;
        Info* next;
    };
    Info* head = new Info();
public:
    Info* get_head() { return head; };
    void clear() {
        Info* it1 = head->next;
        if (it1 == nullptr)return;
        auto it2 = it1->next;
        while (it2 != nullptr) {
            delete(it1);
            it1 = it2;
            it2 = it1->next;
        }
        delete(it1);
        head->next = nullptr;
    }
    int length() {
        int cnt = 0;
        auto it = head->next;
        while (it != nullptr) {
            cnt++;
            it = it->next;
        }
        return cnt;
    }
    int get(int i) {
        auto it = head->next;
        int cur = 1;
        while (it->next && cur < i) {
            it = it->next;
            cur++;
        }
        if (it)return it->data;
        else {
            std::cerr << "Array Index Out of Bounds\n";
            return -1;
        }
    }
    void insert(int i, T x) {
        auto it = head;
        int cur = 0;
        while (it->next && cur < i) {
            it = it->next;
            cur++;
        }
        if (it) {
            Info* newinfo = new Info{ x,it->next };
            it->next = newinfo;
        }
        else {
            std::cerr << "Array Index Out of Bounds\n";
        }
    }
    void remove(int i) {
        auto it = head->next;
        int cur = 1;
        while (it->next && cur < i - 1) {
            it = it->next;
            cur++;
        }
        if (it && it->next) {
            auto tmp = it->next;
            it->next = it->next->next;
            delete(tmp);
        }
        else {
            std::cerr << "Array Index Out of Bounds\n";
        }
    }
    int indexof(T x) {
        auto it = head->next;
        int cur = 1;
        while (it) {
            if (it->data == x)
                return cur;
            it = it->next;
        }
        std::cout << "Not found.\n";
        return -1;
    }
    void reverse() {
        auto it1 = head->next;
        if (!it1)return;
        auto it2 = it1->next;
        it1->next = nullptr;
        if (!it2)return;
        auto it3 = it2->next;
        while (it3) {
            it2->next = it1;
            it1 = it2;
            it2 = it3;
            it3 = it2->next;
        }
        it2->next = it1;
        head->next = it2;
    }
    void display() {
        auto it = head->next;
        while (it != nullptr) {
            std::cout << it->data << ' ';
            it = it->next;
        }
        std::cout << '\n';
    }
};

template<class T>
List<T> merge(List<T>& A, List<T>& B) {
    auto a = A.get_head()->next;
    auto b = B.get_head()->next;
    List<T> C;
    auto c = C.get_head();
    while (a && b) {
        if (a->data <= b->data) {
            c->next = a;
            a = a->next;
            c = c->next;
        }
        else {
            c->next = b;
            b = b->next;
            c = c->next;
        }
    }
    if (a)c->next = a;
    if (b)c->next = b;
    return C;
}

void solve() {
    List<int> A, B;
    int n, m;std::cin >> n >> m;
    for (int i = 0;i < n;++i) {
        int x;std::cin >> x;
        A.insert(i, x);
    }
    for (int i = 0;i < m;++i) {
        int x;std::cin >> x;
        B.insert(i, x);
    }
    A.display();
    B.display();
    List<int> C = merge(A, B);
    C.display();
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