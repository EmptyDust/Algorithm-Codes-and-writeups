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

int n, q;

std::map<std::string, int> field_map;
std::map<std::string, int> value_map;
std::vector<std::string> value_map_inv(1, "");
std::vector<std::pair<int, std::vector<int>>> pre_data;

std::vector<std::pair<int, std::vector<int>>> data;

int idx = 0;
void insert(std::vector<int>& d) {
    data.push_back(std::pair(idx++, d));
}

std::vector<std::pair<int, int>> select_in(std::string& target_name, std::string& field_name, std::vector<int>& values) {
    std::vector<std::pair<int, int>> res;
    int field_id = field_map[field_name];
    int target_id = field_map[target_name];
    // std::cout << field_id << ' ';
    std::sort(data.begin(), data.end(), [&](auto& a, auto& b) {
        return a.second[field_id] < b.second[field_id];
        });
    std::sort(values.begin(), values.end());
    int dsz = data.size(), vsz = values.size();
    for (int i = 0, j = 0;i < dsz && j < vsz;++i) {//坐标
        auto& s = data[i].second[field_id];
        while (j < vsz && values[j] < s) j++;
        if (j == vsz)break;
        if (s == values[j]) {
            // std::cout << s << " " << j << '\n';
            res.push_back({ data[i].first,data[i].second[target_id] });
        }
    }
    std::sort(res.begin(), res.end());
    return res;
}

std::vector<std::pair<int, int>> select(std::string& target_name, std::string& field_name, int& value) {
    std::vector tmp{ value };
    return select_in(target_name, field_name, tmp);
}

int del_in(std::string& field_name, std::vector<int>& values) {
    int field_id = field_map[field_name];
    std::sort(data.begin(), data.end(), [&](auto& a, auto& b) {
        return a.second[field_id] < b.second[field_id];
        });
    std::sort(values.begin(), values.end());
    int cnt = 0;
    int dsz = data.size(), vsz = values.size();
    for (int i = 0, j = 0;i < dsz && j < vsz;++i) {//坐标
        auto& s = data[i].second[field_id];
        while (j < vsz && values[j] < s) j++;
        if (j == vsz)break;
        if (s == values[j]) {
            data[i].second = std::vector<int>(n, inf);
            cnt++;
        }
    }
    return cnt;
}

int del(std::string& field_name, int& value) {
    std::vector tmp{ value };
    return del_in(field_name, tmp);
}

std::vector<std::string> split(std::string& s) {
    std::vector<std::string> ret;ret.push_back("");
    bool f = false;
    for (char ch : s) {
        if (ch == '(')
            f = true;
        if (ch == ',' && !f) {
            ret.push_back("");
            continue;
        }
        ret.back().push_back(ch);
    }
    return ret;
}

int value_idx = 1;
std::vector<int> check(std::string& s, bool f) {
    // if (value_map.count("o")) {
    //     std::cout << "exist:" << value_idx - 1 << '\n';
    // }
    if (s == "begin()") {}
    else if (s == "commit()") {
        pre_data = data;
    }
    else if (s == "abort()") {
        data = pre_data;
    }
    else if (s.substr(0, 6) == "insert") {
        std::string t = s.substr(7);t.pop_back();
        auto vt = split(t);
        std::vector<int> ids;
        for (auto& x : vt) {
            if (!value_map[x]) {
                value_map_inv.push_back(x);
                value_map[x] = value_idx++;
                // std::cout << value_map[x] << ' ';
            }
            // if (!value_map[x]) {
            //     std::cout << value_map.count(x);
            //     std::cout << x << value_map[x] << '\n';
            // }
            ids.push_back(value_map[x]);
        }
        insert(ids);
    }
    else if (s.substr(0, 9) == "select_in") {
        std::string t = s.substr(10);t.pop_back();
        auto vt = split(t);
        auto lim = check(vt[2], 0);
        auto res = select_in(vt[0], vt[1], lim);
        if (f) {
            int sz = res.size();
            std::cout << sz << '\n';
            if (res.size()) {
                std::cout << value_map_inv[res.front().second] << '\n';
                int mid = sz / 2;if (sz % 2 == 0)mid--;
                std::cout << value_map_inv[res[mid].second] << '\n';
                std::cout << value_map_inv[res.back().second] << '\n';
            }
        }
        std::vector<int> ret;
        for (auto& r : res)ret.push_back(r.second);
        return ret;
    }
    else if (s.substr(0, 6) == "select") {
        // std::cout << s << '\n';
        std::string t = s.substr(7);t.pop_back();
        auto vt = split(t);
        auto res = select(vt[0], vt[1], value_map[vt[2]]);
        // std::cout << value_map[vt[2]] << ' ';
        if (f) {
            int sz = res.size();
            // std::cout << "size:" << ' ';
            std::cout << sz << '\n';
            if (res.size()) {
                std::cout << value_map_inv[res.front().second] << '\n';
                int mid = sz / 2;if (sz % 2 == 0)mid--;
                std::cout << value_map_inv[res[mid].second] << '\n';
                std::cout << value_map_inv[res.back().second] << '\n';
            }
        }
        std::vector<int> ret;
        for (auto& r : res)ret.push_back(r.second);
        return ret;
    }
    else if (s.substr(0, 9) == "delete_in") {
        std::string t = s.substr(10);t.pop_back();
        auto vt = split(t);
        auto lim = check(vt[1], 0);
        std::cout << del_in(vt[0], lim) << '\n';
    }
    else if (s.substr(0, 6) == "delete") {
        std::string t = s.substr(7);t.pop_back();
        auto vt = split(t);
        std::cout << del(vt[0], value_map[vt[1]]) << '\n';
    }
    return std::vector<int>();
}

void solve() {
    std::cin >> n >> q;
    // std::cout << "start\n";
    for (int i = 0;i < n;++i) {
        std::string s;std::cin >> s;
        field_map[s] = i;
    }
    while (q--) {
        std::string s;std::cin >> s;
        // std::cout << s << '\n';
        check(s, 1);
    }
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