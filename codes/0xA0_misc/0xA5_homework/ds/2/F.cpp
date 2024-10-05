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
    std::vector<T> data;
public:
    void clear() {
        data.clear();
    }
    int length() {
        return data.size();
    }
    T get(int i) {
        if (i >= data.size())return T();
        return data[i - 1];
    }
    void insert(int i, T x) {
        if (i > data.size()) {
            std::cerr << "Array Index Out of Bounds\n";
            return;
        }
        int sz = data.size();
        data.resize(sz + 1);
        for (int j = sz - 1;j >= std::max(i - 1, 0);--j) {
            data[j + 1] = data[j];
        }
        data[i] = x;
    }
    void remove(int i) {
        if (i > data.size()) {
            std::cerr << "Array Index Out of Bounds\n";
            return;
        }
        --i;
        for (;i < (int)data.size() - 1;++i) {
            data[i] = data[i + 1];
        }
        data.pop_back();
    }
    int indexof(T x) {
        for (int i = 0;i < data.size();++i) {
            if (x == data[i])return i + 1;
        }
        return -1;
    }
    void reverse() {
        for (int i = 0, j = (int)data.size() - 1;i < j;++i, --j) {
            std::swap(data[i], data[j]);
        }
    }
    void push_back(T x) {
        data.push_back(x);
    }
    void display() {
        for (auto x : data)std::cout << x;
        std::cout << '\n';
    }
    T query(int id) {
        for (auto x : data) {
            if (x.id == id) {
                return x;
            }
        }
        return T();
    }
    T query(std::string s, int p) {
        if (p == 1) {
            for (auto x : data) {
                if (x.name == s) {
                    return x;
                }
            }
        }
        else {
            for (auto x : data) {
                if (x.gender == s) {
                    return x;
                }
            }
        }
        return T();
    }
    void change(T x) {
        for (auto& y : data) {
            if (y.id == x.id) {
                y = x;
                break;
            }
        }
    }
    void del(int id) {
        for (int i = 0;i < data.size();++i) {
            if (id == data[i].id) {
                remove(i + 1);
                break;
            }
        }
    }
};

struct Student
{
    int id;
    std::string name;
    std::string gender;
    int english;
    int math;
    friend constexpr std::ostream& operator<<(std::ostream& os, const Student& a) {
        return os << a.id << ' ' << a.name << ' ' << a.gender << ' ' << a.english << ' ' << a.math << std::endl;
    }
};

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const int range = 100;

void solve() {
    List<Student> list;
    int n;std::cin >> n;
    for (int i = 0;i < n;++i) {
        int id, english, math;
        std::string name, gender;
        std::cin >> id >> name >> gender >> english >> math;
        list.push_back(Student(id, name, gender, english, math));
    }
    list.display();
    std::cout << "change:\n";
    int id, english, math;
    std::string name, gender;
    std::cin >> id >> english >> math;
    Student stu = list.query(id);
    std::cout << stu << '\n';
    stu.english = english;
    stu.math = math;
    list.change(stu);
    list.display();
    std::cout << "add:\n";
    std::cin >> id >> name >> gender >> english >> math;
    list.insert(0, Student(id, name, gender, english, math));
    list.display();
    std::cout << "delete:\n";
    std::cin >> id;
    list.del(id);
    list.display();
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