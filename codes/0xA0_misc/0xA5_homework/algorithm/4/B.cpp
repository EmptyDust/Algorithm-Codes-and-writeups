
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s;std::cin >> n >> s;

    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    sort(t.begin(), t.end());

    vector<long long> wait(s, 0);
    double total_time = 0;

    for (int i = 0; i < n; ++i) {
        wait[i % s] += t[i];
        total_time += wait[i % s];
    }

    cout << fixed << setprecision(2) << total_time / n << endl;

    return 0;
}
