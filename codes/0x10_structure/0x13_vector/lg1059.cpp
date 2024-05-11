#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n;cin >> n;
    vector<int> nums(n);
    for (int i = 0;i < n;++i)cin >> nums[i];
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    cout << nums.size() << '\n';
    for (int i = 0;i < nums.size();++i)cout << nums[i] << ' ';
    return 0;
}