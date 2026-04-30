#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--) {
        vector<int> temp(4);
        int f, sum = 4;
        cin >> f;
        for (int i = 0;i < 4;i++) {
            temp[i] = f % 10;
            if (temp[i] == 0)temp[i] += 10;
            f /= 10;
            if (i > 0)sum += abs(temp[i] - temp[i - 1]);
        }
        sum += abs(temp[3] - 1);
        cout << sum << endl;
    }
    return 0;
}
